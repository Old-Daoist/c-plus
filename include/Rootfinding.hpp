#ifndef ROOTFINDING_HPP
#define ROOTFINDING_HPP

#include <functional>

// ========= BASE CLASS ==========
class RootMethod {
protected:
    double tolerance;
    int maxIterations;

public:
    RootMethod(double tol = 1e-6, int maxIter = 1000)
        : tolerance(tol), maxIterations(maxIter) {}

    virtual double solve(std::function<double(double)> func) = 0;
    virtual ~RootMethod() {}
};

// ========= BISECTION =========
class BisectionMethod : public RootMethod {
private:
    double a, b;

public:
    BisectionMethod(double left, double right,
                    double tol = 1e-6, int maxIter = 1000);

    double solve(std::function<double(double)> func) override;
};

// ========= FIXED POINT =======
class FixedPointMethod : public RootMethod {
private:
    double initialGuess;

public:
    FixedPointMethod(double guess,
                     double tol = 1e-6, int maxIter = 1000);

    double solve(std::function<double(double)> g) override;
};

// ========= NEWTON RAPHSON =========
class NewtonRaphsonMethod : public RootMethod {
private:
    double initialGuess;
    std::function<double(double)> derivative;

public:
    NewtonRaphsonMethod(double guess,
                        std::function<double(double)> deriv,
                        double tol = 1e-6, int maxIter = 1000);

    double solve(std::function<double(double)> func) override;
};

#endif
