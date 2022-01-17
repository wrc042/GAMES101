# Eigen Tutorial

## Matrix

### Matrix Class

```cpp
typedef Matrix<float, 3, 1> Vector3f;
typedef Matrix<int, 1, 2> RowVector2i;
typedef Matrix<double, Dynamic, Dynamic> MatrixXd;
typedef Matrix<int, Dynamic, 1> VectorXi;
Matrix<float, 3, Dynamic>;
```

A default constructor is always available, never performs any dynamic memory allocation, and never initializes the matrix coefficients.

always not initialized

Matrices and vectors can also be initialized from lists of coefficients. Prior to C++11, this feature is limited to small fixed-size column or vectors up to size 4

```cpp
Vector2d a(5.0, 6.0);
Vector3d b(5.0, 6.0, 7.0);
Vector4d c(5.0, 6.0, 7.0, 8.0);
```

If C++11 is enabled, fixed-size column or row vectors of arbitrary size can be initialized by passing an arbitrary number of coefficients

```cpp
Vector2i a(1, 2);                      // A column vector containing the elements {1, 2}
Matrix<int, 5, 1> b {1, 2, 3, 4, 5};   // A row-vector containing the elements {1, 2, 3, 4, 5}
Matrix<int, 1, 5> c = {1, 2, 3, 4, 5}; // A column vector containing the elements {1, 2, 3, 4, 5}

MatrixXi a {      // construct a 2x2 matrix
      {1, 2},     // first row
      {3, 4}      // second row
};
Matrix<double, 2, 3> b {
      {2, 3, 4},
      {5, 6, 7},
};

VectorXd a {{1.5, 2.5, 3.5}};             // A column-vector with 3 coefficients
RowVectorXd b {{1.0, 2.0, 3.0, 4.0}};     // A row-vector with 4 coefficients
```

in the C++ language would make `matrix[i,j]` compile to the same thing as `matrix[j]`

comma-initializer:

```cpp
Matrix3f m;
m << 1, 2, 3,
     4, 5, 6,
     7, 8, 9;
std::cout << m;
```

The resize() method is a no-operation if the actual matrix size doesn't change; otherwise it is destructive: the values of the coefficients may change.

conservativeResize()

Trying to change a fixed size to an actually different value will trigger an assertion failure.

Assignment is the action of copying a matrix into another, using operator=. Of course, if the left-hand side is of fixed size, resizing it is not allowed.

**use fixed sizes for very small sizes where you can**, and use dynamic sizes for larger sizes or where you have to. For small sizes, especially for sizes smaller than (roughly) 16, using fixed sizes is hugely beneficial to performance, as it allows Eigen to avoid dynamic memory allocation and to unroll loops. Also, for large enough sizes, say for sizes greater than (roughly) 32, the performance benefit of using fixed sizes becomes negligible.

Finally, depending on circumstances, Eigen can also be more aggressive trying to vectorize (use SIMD instructions) when dynamic sizes are used, see Vectorization.

- MatrixNt for `Matrix<type, N, N>`. For example, MatrixXi for `Matrix<int, Dynamic, Dynamic>`.
- VectorNt for `Matrix<type, N, 1>`. For example, Vector2f for `Matrix<float, 2, 1>`.
- RowVectorNt for `Matrix<type, 1, N>`. For example, RowVector3d for `Matrix<double, 1, 3>`.

- N can be any one of 2, 3, 4, or X (meaning Dynamic).
- t can be any one of i (meaning int), f (meaning float), d (meaning double), cf (meaning complex`<float>`), or cd (meaning complex`<double>`).
