#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/// Representation of time in hours and minutes.
/// Note: The `class` does not have any range checks.
struct Time {
  /// Minutes count.
  int rawValue = 0;

  Time() = default;

  Time(int minutesCount) : rawValue(minutesCount) {}

  Time(int hoursCount, int minutesCount)
      : rawValue(hoursCount * 60 + minutesCount) {}

  int hours() const { return rawValue / 60; }

  int minutes() const { return rawValue % 60; }

  std::string formated() const {
    auto formatedHours = std::to_string(hours());
    if (hours() < 10) {
      formatedHours = '0' + formatedHours;
    }
    auto formatedMinutes = std::to_string(minutes());
    if (minutes() < 10) {
      formatedMinutes = '0' + formatedMinutes;
    }
    return formatedHours + ':' + formatedMinutes;
  }
};

class Train {
private:
  std::string destinationName;
  int number = 0;
  Time departureTime;

  int readNumber() const {
    int number = 0;
    while (true) {
      std::cout << "> Number = ", std::cin >> number;
      if (number <= 0) {
        std::cout << "Error: The train number must be greater than zero.\n";
        continue;
      }

      return number;
    }
  }

  Time readDepartureTime() const {
    std::cout << "> Time:\n";
    int hours = 0;
    int minutes = 0;
    while (true) {
      std::cout << "  > hours = ", std::cin >> hours;
      if (hours < 0 || hours > 23) {
        std::cout << "Error: Value must be in the range [0...23].\n";
        continue;
      }

      std::cout << "  > minutes = ", std::cin >> minutes;
      if (minutes < 0 || minutes > 59) {
        std::cout << "Error: Value must be in the range [0...59].\n";
        continue;
      }

      return Time(hours, minutes);
    }
  }

public:
  Train() {
    std::cout << "> Destination name = ";
    std::cin.get();
    std::getline(std::cin, destinationName);

    number = readNumber();
    departureTime = readDepartureTime();
    std::cout << '\n';
  }

  Train(const std::string &destinationName, int number,
        const Time &departureTime)
      : destinationName(destinationName), number(number),
        departureTime(departureTime) {}

  int getNumber() const { return number; }

  const std::string &getDestinationName() const { return destinationName; }

  const Time &getDepartureTime() const { return departureTime; }

  void print(bool isEmptyLine = true) const {
    std::cout << "Destination name: " << destinationName << '\n'
              << "Number:           " << number << '\n'
              << "Time:             " << departureTime.formated() << '\n';
    if (isEmptyLine) {
      std::cout << '\n';
    }
  }
};

class Station {
private:
  std::vector<Train> trains;

public:
  void addTrain() { trains.push_back(Train()); }

  void printTrains(int number = 0, bool isEmptyLine = true) {
    if (trains.empty()) {
      std::cout << std::string(80, '-') << '\n' << "There are no trains\n";
    }
    for (const auto &train : trains) {
      if (number == 0 || train.getNumber() == number) {
        std::cout << std::string(80, '-') << '\n';
        train.print(false);
      }
    }
    std::cout << std::string(80, '-') << '\n';
    if (isEmptyLine) {
      std::cout << '\n';
    }
  }

  void sortByTrainNumber() {
    for (int i = 0; i < trains.size(); ++i) {
      for (int j = i + 1; j < trains.size(); ++j) {
        if (trains[i].getNumber() > trains[j].getNumber()) {
          std::swap(trains[i], trains[j]);
        }
      }
    }
  }

  void sortByTrainDestinationName() {
    for (int i = 0; i < trains.size(); ++i) {
      for (int j = i + 1; j < trains.size(); ++j) {
        if (trains[i].getDestinationName() > trains[j].getDestinationName()) {
          std::swap(trains[i], trains[j]);
        } else if (trains[i].getDestinationName() ==
                   trains[j].getDestinationName()) {
          if (trains[i].getDepartureTime().rawValue >
              trains[j].getDepartureTime().rawValue) {
            std::swap(trains[i], trains[j]);
          }
        }
      }
    }
  }
};

int main() {
  Station station;
  bool printMenu = true;

  while (true) {
    if (printMenu) {
      std::cout << "> Menu:\n"
                << "    1. Add train\n"
                << "    2. Print trains\n"
                << "    3. Print train by number\n"
                << "    4. Sort by train number and print trains\n"
                << "    5. Sort by train nestination name and print trains\n"
                << "    6. Exit\n";
    }

    int choise = 0;
    std::cout << "> ", std::cin >> choise;

    if (choise >= 1 && choise <= 6) {
      std::cout << '\n';
      printMenu = true;
    }

    switch (choise) {
    case 1:
      station.addTrain();
      break;
    case 2:
      station.printTrains();
      break;
    case 3: {
      int number = 0;
      while (true) {
        std::cout << "> Number = ", std::cin >> number;
        if (number > 0) {
          break;
        }
        std::cout << "Error: Value must be in the range [1...∞].";
      }
      std::cout << '\n';
      station.printTrains(number);
      break;
    }
    case 4:
      station.sortByTrainNumber();
      station.printTrains();
      break;
    case 5:
      station.sortByTrainDestinationName();
      station.printTrains();
      break;
    case 6: // Exit.
      std::cout << "Goodbye ;)\n";
      return 0;
    default:
      std::cerr << "Error: Value must be in the range [1...3].\n";
      printMenu = false;
      break;
    }
  }
  return 0;
}
