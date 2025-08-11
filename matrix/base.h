#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T, typename Derived>
class MatrixExpr {
public:
    T operator()(size_t i, size_t j) const {
        return static_cast<const Derived&>(*this)(i, j);
    }
    size_t rows() const { return static_cast<const Derived&>(*this).rows(); }
    size_t cols() const { return static_cast<const Derived&>(*this).cols(); }
};

template <typename T>
class Matrix : public MatrixExpr<T, Matrix<T>> {
private:
    size_t r, c;
    std::vector<T> data;

public:
    Matrix(size_t rows, size_t cols, T val = T{}) : r(rows), c(cols), data(rows * cols, val) {}

    T& operator()(size_t i, size_t j) { return data[i * c + j]; }
    T operator()(size_t i, size_t j) const { return data[i * c + j]; }

    size_t rows() const { return r; }
    size_t cols() const { return c; }

    template <typename Expr>
    Matrix(const MatrixExpr<T, Expr>& expr) : r(expr.rows()), c(expr.cols()), data(r * c) {
        for (size_t i = 0; i < r; ++i)
            for (size_t j = 0; j < c; ++j)
                (*this)(i, j) = expr(i, j);
    }

    void print() const {
        for (size_t i = 0; i < r; ++i) {
            for (size_t j = 0; j < c; ++j)
                std::cout << (*this)(i, j) << " ";
            std::cout << "\n";
        }
    }
};

#endif
