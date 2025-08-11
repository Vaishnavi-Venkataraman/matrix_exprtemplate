#include "base.h"
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "det.h"
#include <iostream>

template <typename T>
Matrix<T> readMatrixFromUser(const std::string& name) {
    size_t r, c;
    std::cout << "Enter rows and cols for matrix " << name << ": ";
    std::cin >> r >> c;
    Matrix<T> mat(r, c);
    std::cout << "Enter elements of matrix " << name << " (" << r*c << " values):\n";
    for (size_t i = 0; i < r; ++i)
        for (size_t j = 0; j < c; ++j)
            std::cin >> mat(i, j);
    return mat;
}

int main() {
    Matrix<int> A = readMatrixFromUser<int>("A");
    Matrix<int> B = readMatrixFromUser<int>("B");

    try {
        Matrix<int> C = A + B;
        std::cout << "\nA + B:\n"; C.print();
    } catch (const std::exception& e) {
        std::cout << "Addition error: " << e.what() << "\n";
    }

    try {
        Matrix<int> D = A - B;
        std::cout << "\nA - B:\n"; D.print();
    } catch (const std::exception& e) {
        std::cout << "Subtraction error: " << e.what() << "\n";
    }

    try {
        Matrix<int> E = A * B;
        std::cout << "\nA * B:\n"; E.print();
    } catch (const std::exception& e) {
        std::cout << "Multiplication error: " << e.what() << "\n";
    }

    try {
        std::cout << "\ndet(A) = " << determinant(A) << "\n";
    } catch (const std::exception& e) {
        std::cout << "Determinant error: " << e.what() << "\n";
    }
}
