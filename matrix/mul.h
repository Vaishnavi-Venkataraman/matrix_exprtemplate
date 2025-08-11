#ifndef MUL_H
#define MUL_H

#include "base.h"

template <typename T, typename LHS, typename RHS>
class MatrixMul : public MatrixExpr<T, MatrixMul<T, LHS, RHS>> {
private:
    const LHS& lhs;
    const RHS& rhs;
public:
    MatrixMul(const LHS& a, const RHS& b) : lhs(a), rhs(b) {
        if (a.cols() != b.rows())
            throw std::runtime_error("Invalid matrix dimensions for multiplication");
    }
    T operator()(size_t i, size_t j) const {
        T sum = 0;
        for (size_t k = 0; k < lhs.cols(); ++k)
            sum += lhs(i, k) * rhs(k, j);
        return sum;
    }
    size_t rows() const { return lhs.rows(); }
    size_t cols() const { return rhs.cols(); }
};

template <typename T, typename LHS, typename RHS>
MatrixMul<T, LHS, RHS> operator*(const MatrixExpr<T, LHS>& a, const MatrixExpr<T, RHS>& b) {
    return MatrixMul<T, LHS, RHS>(static_cast<const LHS&>(a), static_cast<const RHS&>(b));
}

#endif
