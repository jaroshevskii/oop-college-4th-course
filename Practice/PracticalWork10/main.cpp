//
// Object-oriented programing (college 4th course)
// Practice: Practical work 10
//

#include <iostream>
#include <string>
#include <vector>

/// Matrix storage container.
class Matrix {
private:
  const int rows, columns;
  std::vector<int> grid;

public:
  /// Initializes the matrix with the given number of rows and columns with and
  /// value.
  Matrix(int rows = 0, int columns = 0, int value = 0)
      : rows(rows), columns(columns), grid(rows * columns, value) {}

  /// Initializes the matrix with the given array.
  Matrix(std::vector<std::vector<int>> array)
      : rows(array.front().size()), columns(array.size()) {
    for (const auto &arrayRows : array) {
      for (const auto &arrayElement : arrayRows) {
        grid.push_back(arrayElement);
      }
    }
  }

  /// Provides access to an matrix element.
  int &element(int row, int column) { return grid[(row * columns) + column]; }

  /// Prints a matrix row.
  void printRow(int rowIndex, std::string terminator = "\n") const {
    std::cout << "{";
    for (int i = 0; i < rows; ++i) {
      if (i > 0) {
        std::cout << ", ";
      }
      std::cout << grid[(rowIndex * columns) + i];
    }
    std::cout << '}' << terminator;
  }
  
  /// Prints a matrix column.
  void printColumn(int columnIndex, std::string terminator = "\n") const {
    std::cout << '{';
    for (int i = 0; i < rows; ++i) {
      if (i > 0) {
        std::cout << ", ";
      }
      std::cout << grid[(i * columns) + columnIndex];
    }
    std::cout << '}' << terminator;
  }

  /// Prints the matrix.
  void print(std::string terminator = "\n") const {
    std::cout << '{';
    if (!grid.empty()) {
      std::cout << '\n';
      for (int i = 0; i < columns; ++i) {
        std::cout << "  ";
        printRow(i, "");
        if (i < columns - 1) {
          std::cout << ',';
        }
        std::cout << '\n';
      }
    }
    std::cout << '}' << terminator;
  }
};

int main() {
  Matrix matrix({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

  matrix.printColumn(1);
  std::cout << '\n';
  // Prints "{2, 5, 8}"

  matrix.printRow(1);
  std::cout << '\n';
  // Prints "{4, 5, 6}"

  matrix.print();
  // Prints "{
  //   {1, 4, 7},
  //   {2, 5, 8},
  //   {3, 6, 9}
  // }"
  
  return 0;
}
