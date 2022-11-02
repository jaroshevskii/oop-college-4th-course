#include <iostream>
#include <string>
#include <vector>

/// Offece.
class Office {
private:
  /// Employee.
  class Employee {
  private:
    std::string firstName;
    std::string middleName;
    std::string lastName;

    enum MethodOfReceivingSalary {
      OfficialSalary,
      TimeWorked,
      PercentageOfProfitReceived
    } methodOfReceivingSalary = OfficialSalary;

    // For official Salary.
    int numberOfDaysYouNeedToComplete = 0;
    int numberOfDaysYouComplete = 0;

    // For time worked.
    int hoursWorked = 0;

    // For percentage of profit received.
    double amountOfProfit = 0.0;

    double salary = 0.0;

    /// Returns method of receiving salary read from standart input.
    MethodOfReceivingSalary readMethodOfReceivingSalary() const {
      std::cout << "> Chose method of receiving salary:\n"
                << "    1. Official salary\n"
                << "    2. Time worked\n"
                << "    3. Percentage of profit received\n";

      int value = 0;
      while (true) {
        std::cout << "> ";
        std::cin >> value;

        switch (value) {
        case 1:
          return MethodOfReceivingSalary::OfficialSalary;
        case 2:
          return MethodOfReceivingSalary::TimeWorked;
        case 3:
          return MethodOfReceivingSalary::PercentageOfProfitReceived;
        default:
          std::cerr << "Error: I'm sorry, but these are all method of "
                       "receiving salary.\n";
          break;
        }
      }
    }

    /// Returns method of receiving salary (string).
    std::string getMethodOfReceivingSalaryString() const {
      switch (methodOfReceivingSalary) {
      case MethodOfReceivingSalary::OfficialSalary:
        return "Official salary";
      case MethodOfReceivingSalary::TimeWorked:
        return "Time worked";
      case MethodOfReceivingSalary::PercentageOfProfitReceived:
        return "Percentage of profit received";
        return "???";
      }
    }

    /// Returns calculated salary.
    double calculateSalary() const {
      double salary = 0.0;
      switch (methodOfReceivingSalary) {
      case OfficialSalary: {
        const double salaryPerDay = 7500.0;
        salary = salaryPerDay / numberOfDaysYouNeedToComplete *
                 numberOfDaysYouComplete;
        const double percentagePremium =
            numberOfDaysYouNeedToComplete == numberOfDaysYouComplete ? 25.0
                                                                     : 11;
        const double premium = percentagePremium / 100.0 * salary;
        salary += premium;
        break;
      }
      case TimeWorked: {
        const double payPerHour = 75.0;
        salary = payPerHour * hoursWorked;
        break;
      }
      case PercentageOfProfitReceived: {
        const double persent = 50.0;
        salary = persent / 100.0 * amountOfProfit;
        break;
      }
      }

      const double percentageTaxes = 19.5;
      const double taxes = percentageTaxes / 100.0 * salary;
      salary -= taxes;

      return salary;
    }

    /// Returns number of days you need to complete read from standard input.
    int readNumberOfDaysYouNeedToComplete() {
      int value = 0;
      while (true) {
        std::cout << "> Number of days you need to complete = ";
        std::cin >> value;

        if (value >= 0 && value <= 28) {
          return value;
        }
        std::cerr << "Error: The value must be in the range [0...28].\n";
      }
    }

    /// Returns number of days you complete read from standard input.
    int readNumberOfDaysYouComplete() {
      int value = 0;
      while (true) {
        std::cout << "> Number of days you complete = ";
        std::cin >> value;

        if (value >= 0 && value <= numberOfDaysYouNeedToComplete) {
          return value;
        }
        std::cerr << "Error: The value must be in the range [0..."
                  << numberOfDaysYouNeedToComplete << "].\n";
      }
    }

    /// Returns hours worked read from standard input.
    int readHoursWorked() {
      int value = 0;
      while (true) {
        std::cout << "> Hours worked = ";
        std::cin >> value;

        if (value >= 0 && value <= 224) {
          return value;
        }
        std::cerr << "Error: The value must be in the range [0...224].\n";
      }
    }

    /// Returns amount of profit read from standard input.
    int readAmountOfProfit() {
      int value = 0;
      while (true) {
        std::cout << "> Amount of profit = ";
        std::cin >> value;

        if (value >= 0) {
          return value;
        }
        std::cerr << "Error: The value must be in the range [0...∞].\n";
      }
    }

  public:
    Employee() {
      std::cout << "> First name = ";
      std::cin >> firstName;

      std::cout << "> Midle name = ";
      std::cin >> middleName;

      std::cout << "> Last name = ";
      std::cin >> lastName;

      methodOfReceivingSalary = readMethodOfReceivingSalary();

      switch (methodOfReceivingSalary) {
      case OfficialSalary:
        numberOfDaysYouNeedToComplete = readNumberOfDaysYouNeedToComplete();
        numberOfDaysYouComplete = readNumberOfDaysYouComplete();
        break;
      case TimeWorked:
        hoursWorked = readHoursWorked();
        break;
      case PercentageOfProfitReceived:
        amountOfProfit = readAmountOfProfit();
        break;
      }

      salary = calculateSalary();
      std::cout << '\n';
    }

    /// Prints the employee.
    void print() const {
      std::cout << firstName << ' ' << middleName << ' ' << lastName << ":\n"
                << "  Method of receiving salary:          "
                << getMethodOfReceivingSalaryString() << '\n';

      switch (methodOfReceivingSalary) {
      case OfficialSalary:
        std::cout << "  Number of days you need to complete: "
                  << numberOfDaysYouNeedToComplete << '\n'
                  << "  Number of days you complete:         "
                  << numberOfDaysYouComplete << '\n';
        break;
      case TimeWorked:
        std::cout << "  Hours worked:                        " << hoursWorked
                  << '\n';
        break;
      case PercentageOfProfitReceived:
        std::cout << "  Amount of profit:                    " << amountOfProfit
                  << '\n';
        break;
      }

      std::cout << "  Salary:                              " << salary
                << "\n\n";
    }
  };

  std::vector<Employee> employees;

public:
  /// Adds an employee.
  void addEmployee() { employees.push_back(Employee()); }

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
