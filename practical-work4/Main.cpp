#include <iostream>

class Complex {
private:
  double real = 0.0;
  double imaginary = 0.0;

public:
  Complex() = default;

  Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

  Complex operator+(const Complex &complex) const {
    return Complex(real + complex.real, imaginary + complex.imaginary);
  }

  Complex operator-(const Complex &complex) const {
    return Complex(real - complex.real, imaginary - complex.imaginary);
  }

  Complex operator*(const Complex &complex) const {
    return Complex(real * complex.real, imaginary * complex.imaginary);
  }

  Complex operator*(double number) const {
    return Complex(real * number, imaginary * number);
  }

  Complex operator/(const Complex &complex) const {
    return Complex(real / complex.real, imaginary / complex.imaginary);
  }

  bool operator==(const Complex &complex) const {
    return real == complex.real && imaginary == complex.imaginary;
  }

  bool isConjugateNumbers(const Complex &complex) const {
    return real == complex.real && imaginary == -complex.imaginary;
  }

  Complex pow2() const { return Complex(real * real, imaginary * imaginary); }

  void print() const { std::cout << real << " + " << imaginary << "i\n\n"; }
};

int main() {
  const Complex a(1.1, 2.2);
  const Complex b(3.3, 4.4);
  const Complex c(5.5, 6.6);
  const Complex d(7.7, 8.8);
  bool printMenu = true;

  while (true) {
    if (printMenu) {
      std::cout << "> Menu:\n"
                   "  1. Addition\n"
                   "  2. Subtraction\n"
                   "  3. Multiplication\n"
                   "  4. Multiplication by a number\n"
                   "  5. Division\n"
                   "  6. Check if the numbers are equal\n"
                   "  7. Finding a conjugate number\n"
                   "  8. Exit\n ";
    }

    std::cout << "> ";
    int choise = 0;
    std::cin >> choise;

    if (choise >= 1 && choise <= 8) {
      std::cout << '\n';
      printMenu = true;
    }

    switch (choise) {
    case 1:
      std::cout << "(a + c) + (b + d) = ";
      ((a + c) + (b + d)).print();
      break;
    case 2:
      std::cout << "(a - c) + (b - d) = ";
      ((a - c) + (b - d)).print();
      break;
    case 3:
      std::cout << "(a * c - b * d) + (a * d + b * c) = ";
      ((a * c - b * d) + (a * d + b * c)).print();
      break;
    case 4: {
      std::cout << "> x = ";
      int x = 0;
      std::cin >> x;
      std::cout << '\n';

      std::cout << "(x * a) + (x * b) = ";
      ((a * x) + (b * x)).print();
      break;
    }
    case 5:
      std::cout
          << "(a * c + b * d) / (c^2 + d^2) - (b * c - a * d) / (c^2 + d^2) = ";
      ((a * c + b * d) / (c.pow2() + d.pow2()) -
       (b * c - a * d) / (c.pow2() + d.pow2()))
          .print();
      break;
    case 6:
      std::cout << "a + bi and c + di\n"
                   "a = c: "
                << (a == c) << '\n'
                << "b = d: " << (b == d) << "\n";

      break;
    case 7: {
      bool conjugateNumberFound = false;

      if (a.isConjugateNumbers(b)) {
        conjugateNumberFound = true;
        std::cout << "'a' and 'b' is conjugate numbers\n";
      } else if (a.isConjugateNumbers(c)) {
        conjugateNumberFound = true;
        std::cout << "'a' and 'c' is conjugate numbers\n";
      } else if (a.isConjugateNumbers(d)) {
        conjugateNumberFound = true;
        std::cout << "'a' and 'c' is conjugate numbers\n";
      } else if (b.isConjugateNumbers(c)) {
        conjugateNumberFound = true;
        std::cout << "'b' and 'c' is conjugate numbers\n";
      } else if (b.isConjugateNumbers(d)) {
        conjugateNumberFound = true;
        std::cout << "'b' and 'd' is conjugate numbers\n";
      } else if (c.isConjugateNumbers(d)) {
        conjugateNumberFound = true;
        std::cout << "'b' and 'd' is conjugate numbers\n";
      }

      if (conjugateNumberFound) {
        std::cout << '\n';
      }
      break;
    }
    case 8: // Exit.
      std::cout << "Goodbye ;)\n";
      return 0;
    default:
      std::cerr << "Error: I'm sorry, but these are all available choises.\n";
      printMenu = false;
      break;
    }
  }
  return 0;
}
