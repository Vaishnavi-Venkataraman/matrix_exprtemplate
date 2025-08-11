#ifndef DET_H
#define DET_H

#include "base.h"

template <typename T>
T determinant(const Matrix<T>& mat) {
    if (mat.rows() != mat.cols())
        throw std::runtime_error("Matrix must be square for determinant");

    size_t n = mat.rows();
    if (n == 1) return mat(0, 0);
    if (n == 2) return mat(0,0)*mat(1,1) - mat(0,1)*mat(1,0);

    T det = 0;
    for (size_t p = 0; p < n; ++p) {
        Matrix<T> sub(n - 1, n - 1);
        for (size_t i = 1; i < n; ++i) {
            size_t colIndex = 0;
            for (size_t j = 0; j < n; ++j) {
                if (j == p) continue;
                sub(i - 1, colIndex++) = mat(i, j);
            }
        }
        det += (p % 2 == 0 ? 1 : -1) * mat(0, p) * determinant(sub);
    }
    return det;
}

#endif
