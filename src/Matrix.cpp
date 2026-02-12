#include "../include/Matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

// Constructor
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (r <= 0 || c <= 0) {
        throw std::invalid_argument("Matrix dimensions must be positive");
    }

    data.resize(rows, std::vector<double>(cols, 0.0));
}

// Set value with bounds checking
void Matrix::setValue(int r, int c, double value) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Matrix index out of range");
    }

    data[r][c] = value;
}

// Get value with bounds checking
double Matrix::getValue(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Matrix index out of range");
    }

    return data[r][c];
}

// Display matrix
void Matrix::display() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Getters
int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}

// =========================
// Helper function (Minor)
// =========================
static Matrix getMinor(const Matrix& mat, int skipRow, int skipCol) {

    int n = mat.getRows();
    Matrix minor(n - 1, n - 1);

    int r = 0;

    for (int i = 0; i < n; i++) {

        if (i == skipRow)
            continue;

        int c = 0;

        for (int j = 0; j < n; j++) {

            if (j == skipCol)
                continue;

            minor.setValue(r, c, mat.getValue(i, j));
            c++;
        }

        r++;
    }

    return minor;
}

// =========================
// Determinant
// =========================
double Matrix::determinant() const {

    if (rows != cols)
        throw std::runtime_error("Determinant requires square matrix.");

    // 1x1
    if (rows == 1)
        return data[0][0];

    // 2x2
    if (rows == 2)
        return (data[0][0] * data[1][1]) -
               (data[0][1] * data[1][0]);

    double det = 0.0;

    for (int j = 0; j < cols; j++) {

        Matrix minor = getMinor(*this, 0, j);

        double cofactor =
            ((j % 2 == 0) ? 1 : -1) *
            data[0][j] *
            minor.determinant();

        det += cofactor;
    }

    return det;
}

// =========================
// Inverse (Adjugate Method)
// =========================
Matrix Matrix::inverse() const {

    if (rows != cols)
        throw std::runtime_error("Inverse requires square matrix.");

    double det = determinant();

    if (std::abs(det) < 1e-10)
        throw std::runtime_error("Matrix is singular (det = 0).");

    Matrix adj(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            Matrix minor = getMinor(*this, i, j);

            double cofactor = minor.determinant();

            if ((i + j) % 2 != 0)
                cofactor = -cofactor;

            // Transpose during assignment
            adj.setValue(j, i, cofactor);
        }
    }

    Matrix inv(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inv.setValue(i, j,
                adj.getValue(i, j) / det);
        }
    }

    return inv;
}
