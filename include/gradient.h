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
        void DetermineMinimum(std::vector<double> &x_values, std::vector<double> &y_values);

        /**
         * Overridden function to manage multivariate data
         *
         * @param x_values indicates the set of sets of input values
         * @param y_values indicates the output values
         */
        void DetermineMinimum(std::vector<std::vector<double> > &x_values, std::vector<double> &y_values);

        /**
         * Finds all parameters of single valued equation
         *
         * @return parameters_ class variable
         */
        const std::vector<double> &getParameters() const;

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
         * Represents the derivative of the cost function for multivariate data
         *
         * @param x_values to compute with
         * @param y_values to compute with
         * @param m to represent the upper bound
         * @return the value computed based on the input values
         */
        double CostFunctionDerivative(std::vector<std::vector<double> > &x_values, std::vector<double> &y_values, double m, size_t parameter_count) const;

        /**
         * Function representation of the CalculateHypothesisOutput
         *
         * @param input to compute with the hypothesis values
         * @return output of hypothesis
         */
        double CalculateHypothesisOutput(double input, bool is_multivariate) const;

        /**
         * Function to implement feature scaling for datasets
         *
         * @param x_values to scale down to the appropriate values
         */
        void ScaleParameters(std::vector<double> &x_values);

        const double kPrecision = 0.0000000000000000001;
        const double kLearningRate = 0.01;
        double parameter_m_ = 1;
        double parameter_b_ = 0;

        // Multivariate parameter values
        std::vector<double> parameters_;

        /**
         * Finds the minimum of a values
         *
         * @param values to find minimum of
         * @return the minimum value
         */
        double FindMax(std::vector<double> &values);

        /**
         * Finds the maximum of a values
         *
         * @param values to find the maximum of
         * @return the maximum value
         */
        double FindMin(std::vector<double> &values);

        double FindAverage(std::vector<double> &values);
    };
}
