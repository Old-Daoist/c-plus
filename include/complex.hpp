#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class myComplex {
private:
    float real;
    float imag;
    float extra;

public:
    // Constructors
    myComplex();
    myComplex(float r, float i);
    myComplex(float r, float i, float e);

    // Operations
    myComplex add(const myComplex& c) const;
    myComplex subtract(const myComplex& c) const;
    myComplex multiply(const myComplex& c) const;
    myComplex divide(const myComplex& c) const;

    myComplex conjugate() const;
    float norm() const;

    float getReal() const;
    float getImag() const;

    void display() const;
};

#endif
