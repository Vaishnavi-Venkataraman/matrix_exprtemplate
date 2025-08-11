# Matrix Operations in C++ with Expression Templates

## Overview
This project implements basic matrix operations — **addition, subtraction, multiplication, and determinant calculation** — using **Expression Templates** in C++.  
Expression templates allow us to **avoid unnecessary temporary matrices** and evaluate complex expressions in a single pass, improving performance and memory efficiency.

## Features
- Matrix addition (`+`)
- Matrix subtraction (`-`)
- Matrix multiplication (`*`)
- Determinant calculation (`determinant()`)
- User input for matrix data
- Implementation using **header-only operation classes** (`add.h`, `sub.h`, `mul.h`, `det.h`, `base.h`)
- Build system using `Makefile`

## How It Works (Expression Templates)
1. Operations like `A + B` return **lightweight objects** that store references to operands.
2. No intermediate matrices are created, the result is only calculated when assigned to a real `Matrix` object.
3. The final `Matrix` constructor loops over elements **once**, computing the entire expression.
4. This enables chaining:
   ```cpp
   Matrix<int> R = A + B - C * D;

## Build & Run 
```bash
git clone https://github.com/Vaishnavi-Venkataraman/matrix_exprtemplate.git
cd matrix_exprtemplate/matrix
make
make run
make clean
