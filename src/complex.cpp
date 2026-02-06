#include "complex.hpp"
#include <iostream>
#include <cmath>

// Default constructor
myComplex::myComplex() {
    real = 0;
    imag = 0;
    extra = 0;
}

// Constructor with real & imaginary
myComplex::myComplex(float r, float i) {
    real = r;
    imag = i;
    extra = 0;
}

// Constructor with extra
myComplex::myComplex(float r, float i, float e) {
    real = r;
    imag = i;
    extra = e;
}

// Add
myComplex myComplex::add(const myComplex& c) const {
    return myComplex(real + c.real, imag + c.imag);
}

// Subtract
myComplex myComplex::subtract(const myComplex& c) const {
    return myComplex(real - c.real, imag - c.imag);
}

// Multiply
myComplex myComplex::multiply(const myComplex& c) const {
    float r = (real * c.real) - (imag * c.imag);
    float i = (real * c.imag) + (imag * c.real);
    return myComplex(r, i);
}

// Divide
myComplex myComplex::divide(const myComplex& c) const {
    float denominator = (c.real * c.real) + (c.imag * c.imag);

    if (denominator == 0) {
        std::cerr << "Error: Division by zero\n";
        return myComplex();
    }

    float r = ((real * c.real) + (imag * c.imag)) / denominator;
    float i = ((imag * c.real) - (real * c.imag)) / denominator;
    return myComplex(r, i);
}

// Conjugate
myComplex myComplex::conjugate() const {
    return myComplex(real, -imag);
}

// Norm
float myComplex::norm() const {
    return std::sqrt((real * real) + (imag * imag));
}

// Getters
float myComplex::getReal() const {
    return real;
}

float myComplex::getImag() const {
    return imag;
}

// Display
void myComplex::display() const {
    std::cout << real << " + " << imag << "i" << std::endl;
}
