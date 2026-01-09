#pragma once
#include <iostream>
using namespace std;

class Matrix {

public:
    int** data;
    int rows;
    int cols;

    
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void inputMatrix() {
        cout << "Enter matrix of size " << rows << "x" << cols << ":\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    void displayMatrix() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << "\n";
        }
    }

    Matrix multiply(const Matrix& other) const {
        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    Matrix inverse() const {
        int det = determinant();
        if (det == 0) {
            cerr << "Matrix is not invertible.\n";
            exit(EXIT_FAILURE);
        }

        Matrix adjoint = getAdjoint();
        Matrix inverseMatrix(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                inverseMatrix.data[i][j] = adjoint.data[i][j] / det;
            }
        }

        return inverseMatrix;
    }

    int determinant() const {
        if (rows != cols || (rows != 2 && rows != 3)) {
            cerr << "Determinant calculation is only supported for 2x2 or 3x3 matrices.\n";
            exit(EXIT_FAILURE);
        }

        if (rows == 2) {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        }
        else {
            return data[0][0] * (data[1][1] * data[2][2] - data[2][1] * data[1][2]) -
                data[0][1] * (data[1][0] * data[2][2] - data[2][0] * data[1][2]) +
                data[0][2] * (data[1][0] * data[2][1] - data[2][0] * data[1][1]);
        }
    }

    Matrix getAdjoint() const {
        Matrix adjoint(cols, rows);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                Matrix cofactorMatrix(rows - 1, cols - 1);
                int sign = (i + j) % 2 == 0 ? 1 : -1;

                for (int m = 0, p = 0; m < rows; ++m) {
                    if (m == i) continue;
                    for (int n = 0, q = 0; n < cols; ++n) {
                        if (n == j) continue;
                        cofactorMatrix.data[p][q] = data[m][n];
                        ++q;
                    }
                    ++p;
                }

                adjoint.data[j][i] = sign * cofactorMatrix.determinant();
            }
        }

        return adjoint;
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Matrix addition is only supported for matrices of the same size.\n";
            exit(EXIT_FAILURE);
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }
    Matrix operator%(int modulo) const {
        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] % modulo;
            }
        }

        return result;
    }
};