//
// Object-oriented programing (college 4th course)
// Practice: Practical work 7
//

#include <iostream>
#include <string>
#include <vector>

int readInt(const std::string &lable = "", int nestingLevel = 0) {
  const std::string indent(nestingLevel * 2, ' ');
  const std::string decor = lable == "" ? "> " : "> " + lable + " = ";
  int value = 0;
  std::cout << indent << decor, std::cin >> value;
  return value;
}

int readInt(int min, int max, const std::string &lable = "",
            int nestingLevel = 0) {
  while (true) {
    if (const auto value = readInt(lable, nestingLevel);
        value >= min && value <= max) {
      return value;
    }
    std::cerr << "Error: Value must be in the range [" << min << "..." << max
              << "].\n";
  }
}

class Transportation {
public:
  enum class CargoType { Usual, Oversized, FireHazard, Unknown };

  static CargoType readCargoType(const std::string &lable = "Cargo type",
                                 int nestingLevel = 1) {
    const std::string indent(nestingLevel * 2, ' ');
    std::cout << indent << "> " << lable << ":\n"
              << indent << "    1. Usual\n"
              << indent << "    2. Oversized\n"
              << indent << "    3. FireHazard\n";
    const int choise = readInt(1, 3, "", nestingLevel);
    switch (choise) {
    case 1:
      return CargoType::Usual;
    case 2:
      return CargoType::Oversized;
    case 3:
      return CargoType::FireHazard;
    default:
      return CargoType::Unknown;
    }
  }

private:
  CargoType cargoType = CargoType::Unknown;
  int cargoMass = 0.0;
  int distance = 0;

public:
  Transportation(const std::string &lable) { read(lable); }

  void read(const std::string &lable) {
    std::cout << "> " << lable << ":\n";
    cargoType = readCargoType();
    cargoMass = readInt(1, 10'000, "Cargo mass (kg)", 1);
    distance = readInt(1, 1'000'000, "Distance", 1);
  }

  std::string cargoTypeToString(const CargoType &cargoType) const {
    switch (cargoType) {
    case CargoType::Usual:
      return "Usual";
    case CargoType::Oversized:
      return "Oversized";
    case CargoType::FireHazard:
      return "Fire hazard";
    case CargoType::Unknown:
      return "Unknown";
    }
  }

  void print(const std::string &lable) const {
    std::cout << lable << ":\n"
              << "  Cargo type: " << cargoTypeToString(cargoType) << '\n'
              << "  Cargo mass: " << cargoMass << '\n'
              << "  Distance:   " << distance << '\n';
  }

  CargoType getCargoType() const { return cargoType; }

  int getCargoMass() const { return cargoMass; }

  int getDistance() const { return distance; }
};

class Trucks {
private:
  std::vector<Transportation> trucksTransportations;

public:
  void add() {
    trucksTransportations.push_back(Transportation("Truck transportation"));
    std::cout << '\n';
  }

  void print(const Transportation::CargoType &cargoType =
                 Transportation::CargoType::Unknown) const {
    const std::string separator(80, '-');
    for (const auto &transportation : trucksTransportations) {
      if (cargoType == Transportation::CargoType::Unknown ||
          cargoType == transportation.getCargoType()) {
        std::cout << separator << '\n';
        transportation.print("Truck transportation");
      }
    }
    std::cout << separator << "\n\n";
  }

  void printSortedByDistanceOfTransportation() const {
    Trucks copy(*this);
    auto &transportations = copy.trucksTransportations;
    for (int i = 0; i < transportations.size(); ++i) {
      for (int j = i + 1; j < transportations.size(); ++j) {
        if (transportations[i].getDistance() >
            transportations[j].getDistance()) {
          std::swap(transportations[i], transportations[j]);
        }
      }
    }
    copy.print();
  }

  void printWithLargerCargoMass(int cargoMass) const {
    const std::string separator(80, '-');
    for (const auto &transportation : trucksTransportations) {
      if (transportation.getCargoMass() > cargoMass) {
        std::cout << separator << '\n';
        transportation.print("Truck transportation");
      }
    }
    std::cout << separator << "\n\n";
  }
};

int main() {
  std::cout << "     ______                 __\n"
            << "    /_  __/____ __ __ ____ / /__ ___\n"
            << "     / /  / __// // // __//  '_/(_-<\n"
            << "    /_/  /_/   \\_,_/ \\__//_/\\_\\/___/\n\n";

  Trucks trucks;

  while (true) {
    std::cout
        << "> Menu:\n"
        << "    1. Add truck\n"
        << "    2. Print trucks\n"
        << "    3. Print trucks with a given type of cargo\n"
        << "    4. Print sorted by distance of transportation\n"
        << "    5. Print trucks which have a mass greater than the given\n"
        << "    6. Exit\n";
    const int choise = readInt(0, 6);
    std::cout << '\n';

    switch (choise) {
    case 0:
      std::cout << "  Created with ❤️ by jaroshevskii\n\n";
      break;
    case 1:
      trucks.add();
      break;
    case 2:
      trucks.print();
      break;
    case 3: {
      const auto cargoType =
          Transportation::readCargoType("Transportation cargo type", 0);
      std::cout << '\n';
      trucks.print(cargoType);
      break;
    }
    case 4:
      trucks.printSortedByDistanceOfTransportation();
      break;
    case 5: {
      const int cargoMass = readInt(1, 10'000, "Cargo mass (kg)");
      std::cout << '\n';
      trucks.printWithLargerCargoMass(cargoMass);
      break;
    }
    case 6: // Exit.
      std::cout << "  (* ^ ω ^) goodbye \n\n";
      return 0;
    }
  }
  return 0;
}
