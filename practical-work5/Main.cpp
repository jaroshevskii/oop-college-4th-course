#include <iostream>
#include <vector>

template <typename ValueType> class Matrix {
public:
  using Array = std::vector<ValueType>;
  using Array2d = std::vector<Array>;

private:
  Array2d array2d;
  int rowsCount = array2d.size();
  int colsCount = array2d.size() > 0 ? array2d.front().size() : 0;

public:
  Matrix() = default;

  Matrix(const Array2d &array2d) : array2d(array2d) {}

  Matrix(int rowsCount, int colsCount)
      : array2d(rowsCount, Array(colsCount, 0)) {}

  ~Matrix() = default;

  Matrix operator+(const Matrix &matrix) const {
    if (rowsCount != matrix.rowsCount && colsCount != matrix.colsCount) {
      std::cerr << "Error: Unable to add matrices. The sizes of the matrices "
                   "are different.\n";
      return Matrix();
    }

    Array2d resultArray2d(array2d);

    for (int i = 0; i < rowsCount; ++i) {
      for (int j = 0; j < colsCount; ++j) {
        resultArray2d[i][j] = array2d[i][j] + matrix.array2d[i][j];
      }
    }

    return Matrix(resultArray2d);
  }

  Matrix operator-(const Matrix &matrix) const {
    if (rowsCount != matrix.rowsCount && colsCount != matrix.colsCount) {
      std::cerr << "Error: Unable to substract matrices. The sizes of the "
                   "matrices are different.\n";
      return Matrix();
    }

    Array2d resultArray2d(array2d);

    for (int i = 0; i < rowsCount; ++i) {
      for (int j = 0; j < colsCount; ++j) {
        resultArray2d[i][j] = array2d[i][j] - matrix.array2d[i][j];
      }
    }

    return Matrix(resultArray2d);
  }

  /// Note: The function does not correctly add matrices with different sizes.
  Matrix operator*(const Matrix &matrix) const {
    if (rowsCount != matrix.rowsCount) {
      std::cerr
          << "Error: Matrices cannot be multiplied. Сolumns count of the first "
             "matrix is not equal to rows count of the second matrix.\n";
      return Matrix();
    }

    Array2d resultArray2d(matrix.rowsCount, Array(colsCount, 0));

    for (int i = 0; i < colsCount; ++i) {
      for (int j = 0; j < rowsCount; ++j) {
        for (int k = 0; k < matrix.colsCount; ++k) {
          resultArray2d[i][j] += array2d[i][k] * matrix.array2d[k][j];
        }
      }
    }

    return Matrix(resultArray2d);
  }

  Matrix operator*(const ValueType &multiplier) const {
    Array2d resultArray2d(array2d);

    for (auto &array : resultArray2d) {
      for (auto &value : array) {
        value *= multiplier;
      }
    }

    return Matrix(resultArray2d);
  }

  void print() const {
    std::cout << "Matrix:\n";
    if (rowsCount == 0 && colsCount == 0) {
      std::cout << "  Empty\n\n";
      return;
    }

    for (auto &array : array2d) {
      std::cout << ' ';
      for (auto &value : array) {
        std::cout << ' ' << value;
      }
      std::cout << '\n';
    }
    std::cout << '\n';
  }

  void fillRandomNumbers() {
    srand(time(nullptr));
    for (auto &array : array2d) {
      for (auto &value : array) {
        value = 1 + rand() % 19;
      }
    }
  }

  void transpose() {
    Array2d resultArray2d(rowsCount, Array(colsCount, 0));
    for (int i = 0; i < rowsCount; ++i) {
      for (int j = 0; j < colsCount; ++j) {
        resultArray2d[j][i] = array2d[i][j];
      }
    }
    array2d = resultArray2d;
  }
};

int main() {
  Matrix<int> a({{1, 2, 3}, {1, 2, 3}, {1, 2, 3}});
  a.transpose();
  a.print();

  const Matrix<int> b({{1, 2, 3}, {1, 2, 3}, {1, 2, 3}});
  b.print();

  const auto c = a * b;
  c.print();

  Matrix<int> aaa;
  return 0;
}
