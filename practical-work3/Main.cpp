#include <iostream>
#include <string>
#include <vector>

/// Offece.
class Office {
private:
  /// Employee.
  class Employee {
  private:
    std::string lastNameAndInitials;

    enum class PositionOfTariffGrid {
      Specialist = 1,
      Specialist1stCategory,
      Specialist2ndCategory,
      SpecialistHighestCategory,
      HeadDepartment,
      Director,
      Count
    } positionOfTariffGrid = PositionOfTariffGrid::Specialist;

    double rate = 0.0;
    double premium = 0.0;
    double salary = 0.0;

    /// Returns position of tariff grid read from standart input.
    PositionOfTariffGrid readPositionOfTariffGrid() const {
      std::cout << "> Chose position of tariff grid:\n"
                << "    1. Specialist\n"
                << "    2. Specialist 1st category\n"
                << "    3. Specialist 2nd category\n"
                << "    4. Specialist highest category\n"
                << "    5. Head department\n";

      int value = 0;
      while (true) {
        std::cout << "> ";
        std::cin >> value;

        switch (value) {
        case 1:
          return PositionOfTariffGrid::Specialist;
        case 2:
          return PositionOfTariffGrid::Specialist1stCategory;
        case 3:
          return PositionOfTariffGrid::Specialist2ndCategory;
        case 4:
          return PositionOfTariffGrid::SpecialistHighestCategory;
        case 5:
          return PositionOfTariffGrid::HeadDepartment;
        default:
          std::cerr << "Error: I'm sorry, but these are all positions of "
                       "tariff grid.\n";
          break;
        }
      }
    }

    /// Returns position of tariff grid (string).
    std::string getPositionOfTariffGridString() const {
      switch (positionOfTariffGrid) {
      case PositionOfTariffGrid::Specialist:
        return "Specialist";
      case PositionOfTariffGrid::Specialist1stCategory:
        return "Specialist1stCategory";
      case PositionOfTariffGrid::Specialist2ndCategory:
        return "Specialist2ndCategory";
      case PositionOfTariffGrid::SpecialistHighestCategory:
        return "SpecialistHighestCategory";
      case PositionOfTariffGrid::HeadDepartment:
        return "HeadDepartment";
      default:
        return "???";
      }
    }

    /// Returns calculated rate.
    double calculateRate() const {
      return static_cast<int>(positionOfTariffGrid) * 1000;
    }

    /// Returns calculated premium.
    double calculatePremium(double avarageRate) {
      if (rate < avarageRate) {
        return rate / 100 * 50;
      }
      return rate / 100 * 30;
    }
    
    /// Returns calculated salary.
    double calculateSalary() const { return rate + premium; }

  public:
    Employee(double avarageRate) {
      std::cout << "> Last name and initials = ";
      std::cin.get(); // Fix '\n' bug.
      std::getline(std::cin, lastNameAndInitials);

      positionOfTariffGrid = readPositionOfTariffGrid();
      rate = calculateRate();
      premium = calculatePremium(avarageRate);
      salary = calculateSalary();
      
      std::cout << "Avarage rate: " << avarageRate << '\n';

      std::cout << '\n';
    }

    /// Returns rate.
    double getRate() const { return rate; }

    /// Prints the employee.
    void print() const {
      std::cout << lastNameAndInitials << ":\n"
                << "  Position of tariff grid: "
                << getPositionOfTariffGridString() << '\n'
                << "  Rate:                    " << rate << '\n'
                << "  Premium:                 " << premium << '\n'
                << "  Salary:                  " << salary << "\n\n";
    }
  };

  std::vector<Employee> employees;

  /// Returns calculated avarage rate.
  double calculateAvarageRate() const {
    if (employees.size() == 0) {
      std::cerr << "It is impossible to calculate the average rate without any "
                   "employee.\n";
      return 0.0;
    }

    double totalRate = 0.0;
    for (const auto &employee : employees) {
      totalRate += employee.getRate();
    }
    return totalRate / employees.size();
  }

public:
  /// Adds an employee.
  void addEmployee() { employees.push_back(Employee(calculateAvarageRate())); }

  /// Prints employees.
  void printEmployees() const {
    if (employees.empty()) {
      std::cout << "There is no employee in the office.\n\n";
    }

    for (const auto &employee : employees) {
      employee.print();
    }
  }
};

int main() {
  Office office;
  bool printMenu = true;

  while (true) {
    if (printMenu) {
      std::cout << "> Menu:\n"
                << "    1. Add employee\n"
                << "    2. Print employees\n"
                << "    3. Exit\n";
    }

    std::cout << "> ";
    int choise = 0;
    std::cin >> choise;

    if (choise >= 1 && choise <= 3) {
      std::cout << '\n';
      printMenu = true;
    }

    switch (choise) {
    case 1:
      office.addEmployee();
      break;
    case 2:
      office.printEmployees();
      break;
    case 3: // Exit.
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
