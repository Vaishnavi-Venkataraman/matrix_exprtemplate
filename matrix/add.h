#ifndef ADD_H
#define ADD_H

#include "base.h"

template <typename T, typename LHS, typename RHS>
class MatrixAdd : public MatrixExpr<T, MatrixAdd<T, LHS, RHS>> {
private:
    const LHS& lhs;
    const RHS& rhs;
public:
    MatrixAdd(const LHS& a, const RHS& b) : lhs(a), rhs(b) {
        if (a.rows() != b.rows() || a.cols() != b.cols())
            throw std::runtime_error("Matrix dimensions must match for addition");
    }
    T operator()(size_t i, size_t j) const { return lhs(i, j) + rhs(i, j); }
    size_t rows() const { return lhs.rows(); }
    size_t cols() const { return lhs.cols(); }
};

template <typename T, typename LHS, typename RHS>
MatrixAdd<T, LHS, RHS> operator+(const MatrixExpr<T, LHS>& a, const MatrixExpr<T, RHS>& b) {
    return MatrixAdd<T, LHS, RHS>(static_cast<const LHS&>(a), static_cast<const RHS&>(b));
}

#endif
