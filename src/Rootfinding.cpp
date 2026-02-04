#include "../Include/Rootfinding.hpp"
#include <stdexcept>
#include <cmath>

double RootFinding::bisection(
    std::function<double(double)> func,
    double left,
    double right,
    double tolerance,
    int maxIterations
) {
    double fLeft = func(left);
    double fRight = func(right);

    // Bisection requirement
    if (fLeft * fRight >= 0) {
        throw std::invalid_argument(
            "Bisection method requires opposite signs at interval endpoints"
        );
    }

    double mid = 0.0;

    for (int i = 0; i < maxIterations; i++) {
        mid = (left + right) / 2.0;
        double fMid = func(mid);

        // Root found
        if (std::abs(fMid) < tolerance) {
            return mid;
        }

        // Narrow the interval
        if (fLeft * fMid < 0) {
            right = mid;
            fRight = fMid;
        } else {
            left = mid;
            fLeft = fMid;
        }
    }

    throw std::runtime_error("Bisection method did not converge");
}
