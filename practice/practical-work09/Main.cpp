//
// Object-oriented programing (college 4th course)
// Practice: Practical work 9
//

#include <iostream>
#include <vector>

template <typename Element> class Array {
private:
  std::vector<Element> data;

public:
  /// Creates a empty array.
  Array() = default;

  /// Creates a array containing the specified number of a single, repeated
  /// value.
  Array(const Element &repeating, int count) : data(count, repeating) {}

  /// Prints textual representation of array to standart output.
  void print() const {
    std::cout << '{';
    for (int i = 0; i < data.size(); ++i) {
      if (i == 0) {
        std::cout << data[i] << ',';
      } else if (i != data.size() - 1) {
        std::cout << ' ' << data[i] << ',';
      } else {
        std::cout << ' ' << data[i];
      }
    }
    std::cout << "}\n";
  }

  void print(int index) const { std::cout << data.at(index) << '\n'; }

  Element &operator[](int index) { return data.at(index); }

  Array operator+(const Array<Element> &array) const {
    if (data.size() != array.data.size()) {
      std::cout << "Error: Sizes must be equal\n";
      return Array<Element>();
    }

    Array<Element> result;
    for (int i = 0; i < data.size(); ++i) {
      result.data.push_back(data[i] + array.data[i]);
    }
    return result;
  }

  Array operator-(const Array<Element> &array) const {
    if (data.size() != array.data.size()) {
      std::cout << "Error: Sizes must be equal\n";
      return Array<Element>();
    }

    Array<Element> result;
    for (int i = 0; i < data.size(); ++i) {
      result.data.push_back(data[i] - array.data[i]);
    }
    return result;
  }

  void operator*=(const Element &element) {
    for (auto &value : data) {
      value *= element;
    }
  }

  void operator/=(const Element &element) {
    if (element == 0) {
      std::cout << "Error: Cannot devide by zero\n";
    }
    for (auto &value : data) {
      value /= element;
    }
  }
};

int main() {
  Array<int> array(2, 5);
  array.print();
  // Prints "{2, 2, 2, 2, 2}"

  std::cout << '\n';

  (array + Array<int>(4, 5)).print();
  // Prints "{6, 6, 6, 6, 6}"
  (array - Array<int>(5, 5)).print();
  // Prints "{-3, -3, -3, -3, -3}"

  std::cout << '\n';

  array *= 6;
  array.print();
  // Prints "{12, 12, 12, 12, 12}"

  array /= 4;
  array.print();
  // Prints "{3, 3, 3, 3, 3}"

  std::cout << '\n';

  array[2] = 5;
  array.print();
  // Prints "{3, 3, 5, 3, 3}"

  return 0;
}