#ifndef ROOTFINDING_HPP
#define ROOTFINDING_HPP

#include <functional>

class RootFinding {
public:
    // Bisection Method
    static double bisection(
        std::function<double(double)> func,
        double left,
        double right,
        double tolerance = 1e-6,
        int maxIterations = 1000
    );
};

#endif
