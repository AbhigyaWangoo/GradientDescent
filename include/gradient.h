//
// Created by Abhi Wangoo on 1/14/21.
//

#pragma once

#include <iostream>

#include "vector"

namespace gradientDescent {

    class gradient {
    public:
        void determineMinimum(std::vector<double> x_values, std::vector<double> y_values);

    private:
        double percision_ = 0.000001;
        double learning_rate_ = 0.001;

        double CostFunctionDerivative(double parameter_m, std::vector<double> &y_values, std::vector<double> &x_values, double m);
    };
}
