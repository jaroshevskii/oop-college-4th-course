#include <iostream>
#include <string>
#include <vector>

/// Offece.
class Office {
private:
  /// employee.
  class Employee {
  private:
    std::string firstName;
    std::string lastName;
    std::string gender;
    int yearOfBirth = 0;
    int yearOfEmployment = 0;

    /// Returns year of birth read from standard input.
    int readYearOfBirth() {
      int value = 0;
      while (true) {
        std::cout << "> Year of birth = ";
        std::cin >> value;

        if (value >= 1900) {
          return value;
        }
        if (value == 0) {
          std::cout << "Note: Hello Jesus.\n";
          return value;
        }
        std::cerr << "Error: I doubt that you were born before 1900.\n";
      }
    }

    /// Returns gender read from standart input.
    std::string readGender() {
      std::cout << "> Chose gender:\n"
                << "    1. Man\n"
                << "    2. Woman\n"
                << "    3. Pickle (for other people)\n";

      int value = 0;
      while (true) {
        std::cout << "> Gender = ";
        std::cin >> value;

        switch (value) {
        case 1:
          return "Man";
        case 2:
          return "Woman";
        case 3:
          return "Picle";
        default:
          std::cerr
              << "Error: I'm sorry, but these are all available genders.\n";
          break;
        }
      }
    }

    /// Returns year of employment forom standart input.
    int readYearOfEmployment() {
      int value = 0;
      while (true) {
        std::cout << "> Year of employment = ";
        std::cin >> value;

        if (value > yearOfBirth) {
          return value;
        }
        std::cerr << "Error: Year of employment must be greater than the year "
                     "of birth.\n";
      }
    }

  public:
    Employee() {
      std::cout << "> First name = ";
      std::cin >> firstName;
      std::cout << "> Last name = ";
      std::cin >> lastName;

      gender = readGender();
      yearOfBirth = readYearOfBirth();
      yearOfEmployment = readYearOfEmployment();

      std::cout << '\n';
    }

    /// Returns first name.
    const std::string &getFirstName() const { return firstName; }

    /// Returns last name.
    const std::string &getLastName() const { return lastName; }

    /// Returns gender.
    const std::string &getGender() const { return gender; }

    /// Returns year of birth.
    int getYearOfBirth() const { return yearOfBirth; }

    /// Returns year of Employment.
    int getYearOfEmployment() const { return yearOfEmployment; }

    /// Prints the employee.
    void print() const {
      std::cout << firstName << ' ' << lastName << ":\n"
                << "  Year of birth:      " << yearOfBirth << '\n'
                << "  Gender:             " << gender << '\n'
                << "  Year of employment: " << yearOfEmployment << "\n\n";
    }
  };

  std::vector<Employee> employees;

public:
  /// Adds an employee.
  void addemployee() { employees.push_back(Employee()); }

  /// Prints employees.
  void printemployees() const {
    for (const auto &employee : employees) {
      employee.print();
    }
  }

  /// Prints women who have been working for at least 2 years and over 30 years.
  void printSpecialEmployees() const {
    // Used for calculations.
    const int currentYear = 2022;

    bool foundAtLeastOneEmployee = false;

    for (const auto &employee : employees) {
      // Prints employee if the worker fits the condition.
      if (employee.getGender() == "Woman" &&
          currentYear - employee.getYearOfEmployment() >= 2 &&
          currentYear - employee.getYearOfBirth() >= 30) {
        foundAtLeastOneEmployee = true;
        employee.print();
      }

      std::cout << (employee.getGender() == "Woman") << '\n'
                << currentYear - employee.getYearOfEmployment() << '\n'
                << currentYear - employee.getYearOfBirth() << '\n';
    }

    if (!foundAtLeastOneEmployee) {
      std::cout << "Note: No special eployee found.\n\n";
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
                << "    3. Print women who have been working for at least 2 "
                   "years and over 30 years\n"
                << "    4. Exit\n";
    }

    std::cout << "> Choise = ";
    int choise = 0;
    std::cin >> choise;

    if (choise >= 1 && choise <= 3) {
      std::cout << '\n';
      printMenu = true;
    }

    switch (choise) {
    case 1:
      office.addemployee();
      break;
    case 2:
      office.printemployees();
      break;
    case 3:
      office.printSpecialEmployees();
      break;
    case 4: // Exit.
      std::cout << "\nGoodbye ;)\n";
      return 0;
    default:
      std::cerr << "Error: I'm sorry, but these are all available choises.\n";
      printMenu = false;
      break;
    }
  }
  return 0;
}