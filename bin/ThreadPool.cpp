#include "ThreadPool.h"

/* create a pool of num_threads detached threads */
template<typename T>
ThreadPool<T>::ThreadPool(function<void(T &)> &task_func, int num_threads) {
    task_func = task_func;
    terminate = false;
    int i;
    for (i = 0; i < num_threads; i++) {
        threads.emplace_back(thread([this]() -> void { thread_func(); }));
        threads.back().detach();
    }
}

template<typename T>
void ThreadPool<T>::enqueue(T t) {
    unique_lock lock{m};
    jobs.push(t);
    cv.notify_one();
}

template<typename T>
void ThreadPool<T>::thread_func() {
    T t;
    while (true) {
        {
            unique_lock lock{m};
            while (jobs.empty() && !terminate)
                cv.wait(lock);
            if (terminate)
                return;
            t = jobs.front();
            jobs.pop();
            // if the task is a termination task, signal other threads and exit
            if (t.isStopTask()) {
                terminate = true;
                cv.notify_all();
                return;
            }
        }
        this->task_func(t);
    }
}

template<> ThreadPool<AlternationTask>::ThreadPool(function<void(AlternationTask &)> &task_func, int num_threads);