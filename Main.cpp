#include <iostream>
#include <exception>

#include "Include/Matrix.hpp"
#include "Include/Rootfinding.hpp"
#include "Include/Utils.hpp"

// Function for root finding
double equation(double x) {
    return x * x - 4;   // root = 2
}

int main() {
    try {
        Utils::print("=== Matrix Example ===");

        Matrix mat(2, 2);
        mat.setValue(0, 0, 1);
        mat.setValue(0, 1, 2);
        mat.setValue(1, 0, 3);
        mat.setValue(1, 1, 4);
        mat.display();

        Utils::print("\n=== Root Finding (Bisection Method) ===");

        double root = RootFinding::bisection(equation, 0, 5);
        std::cout << "Root found: " << root << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
    }

    return 0;
}
