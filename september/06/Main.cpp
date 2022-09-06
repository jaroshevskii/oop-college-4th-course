#include <iostream>
#include <string>
#include <vector>

/// Offece.
class Office {
private:
  /// Employer.
  class Employer {
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
        std::cout << "  Gender = ";
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
    Employer() {
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
                << "  Year of employment: " << yearOfEmployment << '\n';
    }
  };

  std::vector<Employer> employers;

public:
  /// Adds an employee.
  void addEmployer() { employers.push_back(Employer()); }

  /// Prints employees.
  void printEmployers() const {
    for (const auto &employer : employers) {
      employer.print();
      std::cout << '\n';
    }
  }

  /// Prints women who have been working for at least 2 years and over 30 years.
  void printSpecialEmployers() {
    // Used for calculations.
    const int currentYear = 2022;

    for (const auto &employer : employers) {
      // Prints if the worker fits the condition.
      if (employer.getFirstName() == "Woman" &&
          currentYear - employer.getYearOfEmployment() >= 2 &&
          currentYear - employer.getYearOfBirth() >= 30) {
        employer.print();
      }
    }
    std::cout << '\n';
  }
};

int main() {
  Office office;
  bool isPrintMenu = true;

  while (true) {
    if (isPrintMenu) {
      std::cout << "> Menu:\n"
                << "    1. Add a worker\n"
                << "    2. Pint workers\n"
                << "    3. Prints women who have been working for at least 2 "
                   "years and over 30 years\n"
                << "    4. Exit\n";
    }

    std::cout << "> Choise = ";
    int choise = 0;
    std::cin >> choise;

    if (choise >= 1 && choise <= 3) {
      std::cout << '\n';
      isPrintMenu = true;
    }

    switch (choise) {
    case 1:
      office.addEmployer();
      break;
    case 2:
      office.printEmployers();
      break;
    case 3:
      office.printSpecialEmployers();
      break;
    case 4: // Exit.
      return 0;
    default:
      std::cerr << "Error: I'm sorry, but these are all available choises.\n";
      isPrintMenu = false;
      break;
    }
  }
  return 0;
}