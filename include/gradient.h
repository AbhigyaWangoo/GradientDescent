//
// Created by Abhi Wangoo on 1/14/21.
//

#pragma once

#include <iostream>

#include "vector"

namespace gradientDescent {

    class Gradient {
    public:
        /**
         * Core functionality, determines the function matching the data and prints it out
         *
         * @param x_values to predict with
         * @param y_values to predict with
         */
        void DetermineMinimum(std::vector<double> x_values, std::vector<double> y_values);

    private:
        /**
         * Represents the derivative of the cost function
         *
         * @param x_values to compute with
         * @param y_values to compute with
         * @param m to represent the upper bound
         * @param is_const to indicate whether the parameter has a coefficient or not
         * @return the value computed based on the input values
         */
        double CostFunctionDerivative(std::vector<double> &x_values, std::vector<double> &y_values, double m, bool is_const) const;

        /**
         * Function representation of the CalculateHypothesisOutput
         *
         * @param input to compute with the hypothesis values
         * @return output of hypothesis
         */
        double CalculateHypothesisOutput(double input) const;

        const double kPrecision = 0.0000000000000000001;
        const double kLearningRate = 0.01;
        double parameter_m_ = 1;
        double parameter_b_ = 0;
    };
}
