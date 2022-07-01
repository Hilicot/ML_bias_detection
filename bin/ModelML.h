/** An abstract class to be implemented by all other model classes.
 * */
#ifndef SDP_PROJECT_MODELML_H
#define SDP_PROJECT_MODELML_H

#include <Eigen/core>

class ModelML {
    public:
        Eigen::VectorXf getParams() const;
        void setParams(const Eigen::VectorXf &params);
        /** This function is used to train a model.
        *  @param train is a matrix having a row for each sample and a column for each feature
        *  @param responses is a column vector storing the expected responses, one for each sample
        * */
        virtual void fit(const Eigen::MatrixXf &train, const Eigen::VectorXf &responses) = 0;
        /** This function is used to predict responses using a model.
        *  @param samples is a matrix having a row for each sample and a column for each feature
        *  @param predictions is a column vector which WILL store the computed responses, one for each sample
        * */
        virtual void predict(const Eigen::MatrixXf &samples, Eigen::VectorXf &predictions) = 0;
    protected:
        Eigen::VectorXf _params;
};


#endif //SDP_PROJECT_MODELML_H