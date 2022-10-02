#include <cmath>
#include <iostream>
#include <random>
#include <vector>

/// Trapeze.
class Trapeze {
public:
  /// Point.
  struct Point {
    double x = 0.0;
    double y = 0.0;

    double distanceTo(const Point &point) const {
      return std::sqrt(std::pow(point.x - x, 2) + std::pow(point.y - y, 2));
    }
  };

private:
  Point a;
  Point b;
  Point c;
  Point d;

public:
  Trapeze() = default;

  Trapeze(const Point &a, const Point &b, const Point &c, const Point &d)
      : a(a), b(b), c(c), d(d) {}

  bool isEquilateral() const { return a.distanceTo(c) == b.distanceTo(d); }

  double perimeter() const {
    return a.distanceTo(b) + b.distanceTo(c) + c.distanceTo(d) +
           d.distanceTo(a);
  }

  double height() const { return b.distanceTo({b.x, a.y}); }

  double area() const {
    return (a.distanceTo(d) + b.distanceTo(c)) / 2.0 * height();
  }

  void print() const {
    std::cout << "Sides lenght:\n"
              << "  AB: " << a.distanceTo(b) << '\n'
              << "  BC: " << b.distanceTo(c) << '\n'
              << "  CD: " << c.distanceTo(d) << '\n'
              << "  DA: " << d.distanceTo(a) << '\n'
              << "Perimeter: " << perimeter() << '\n'
              << "Area:      " << area() << "\n\n";
  }
};

int main() {
  const double min = 0.0;
  const double max = 100.0;

  std::random_device device;
  std::default_random_engine engine(device());
  std::uniform_real_distribution<double> distribution(min, max);
  
  const int trapezesCount = 10;
  std::vector<Trapeze> trapezes(trapezesCount);
  double areaAverageSum = 0.0;

  for (auto &trapeze : trapezes) {
    trapeze = Trapeze({distribution(engine), distribution(engine)},
                      {distribution(engine), distribution(engine)},
                      {distribution(engine), distribution(engine)},
                      {distribution(engine), distribution(engine)});
    areaAverageSum += trapeze.area();
  }

  areaAverageSum /= trapezesCount;
  int areasCount = 0;

  for (const auto &trapeze : trapezes) {
    if (trapeze.area() > areaAverageSum) {
      trapeze.print();
      ++areasCount;
    }
  }

  std::cout << "Areas count: " << areasCount << "\n\n";
  return 0;
}
