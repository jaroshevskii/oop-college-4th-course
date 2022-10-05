#include <cerrno>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

/// Prism.
class Prism {
private:
  double height = 0.0;
  double sidesLength = 0.0;
  int facesCount = 0;

public:
  Prism(double height, double sidesLenght, int facesCount)
      : height(height), sidesLength(sidesLenght),
        facesCount(facesCount >= 3 ? facesCount : 3) {}

  void print() const {
    std::cout << "Height:       " << height << '\n'
              << "Sides lenght: " << sidesLength << '\n'
              << "Faces count:  " << facesCount << "\n\n";
  }

  double areaSide() const { return sidesLength * facesCount * height; }

  double areaBase() const {
    return (facesCount * std::pow(sidesLength, 2)) /
           (4 * std::tan(180 / facesCount));
  }

  double area() const { return areaSide() + 2 * areaBase(); }
};

int main() {
  const Prism prism(10.0, 10.0, 3);
  prism.print();

  std::cout << "Area: " << prism.area() << "\n\n";
  return 0;
}
