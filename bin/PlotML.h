#ifndef SDP_PROJECT_PLOTML_H
#define SDP_PROJECT_PLOTML_H

#include <Eigen/Core>

class PlotML {
    public:
        PlotML(int fold_number);
        void alternation_plot(const std::string og_attr, const std::string alternated_attr, const std::string pred_feat,
                              const Eigen::VectorXf &og_pred, const Eigen::VectorXf &alternated_pred);
    private:
        int _fold_number;
};


#endif //SDP_PROJECT_PLOTML_H
