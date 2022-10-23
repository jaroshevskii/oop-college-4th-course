//
// Object-oriented programing (college 4th course)
// Practical work 1
//

#include <cmath>
#include <iostream>

class Triangle {
private:
  double a = 0, b = 0, c = 0;

public:
  Triangle() = default;

  Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

  double area() const {
    const double p = (a + b + c) / 2.0; // Semi perimeter.
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
  }

  void print() const {
    std::cout << "Triangle: a = " << a << ", b = " << b << ", c = " << c << '\n'
              << "  Area: " << area() << "\n\n";
  }
};

class Box {
private:
  double width = 0.0;
  double height = 0.0;
  double lenght = 0.0;

public:
  Box(double width, double height, double lenght)
      : width(width), height(height), lenght(lenght) {}

  double getWidth() const { return width; }
  double getHeight() const { return height; }
  double getLenght() const { return lenght; }

  void setWidth(double newValue) { width = newValue; }
  void setHeight(double newValue) { width = newValue; }
  void setLenght(double newValue) { lenght = newValue; }

  double volume() const { return width * height * lenght; }

  void print() const {
    std::cout << "Box: width = " << width << ", height = " << height
              << ", length = " << lenght << '\n'
              << "  Volume: " << volume() << "\n\n";
  }
};

int main() {
  Triangle(3.0, 3.0, 3.0).print();
  Box(1.0, 2.0, 3.0).print();
  return 0;
}