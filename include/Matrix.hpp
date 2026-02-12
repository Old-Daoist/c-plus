#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

public:
    // Constructor
    Matrix(int r, int c);

    // Set value at position (r, c)
    void setValue(int r, int c, double value);

    // Get value from position (r, c)
    double getValue(int r, int c) const;

    // Display matrix
    void display() const;

    // NEW FUNCTIONS
    int getRows() const;
    int getCols() const;

    double determinant() const;
    Matrix inverse() const;
};

#endif
