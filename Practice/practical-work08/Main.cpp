#include <iostream>
#include <limits>
#include <string>
#include <vector>

int readInt(const std::string &lable, int nestingLevel = 0) {
  const std::string indent(nestingLevel * 2, ' ');
  int value = 0;
  std::cout << indent << "> " << lable << " = ", std::cin >> value;
  return value;
}

int readInt(int min, int max, const std::string &lable, int nestingLevel = 0) {
  while (true) {
    if (const auto value = readInt(lable, nestingLevel);
        value >= min && value <= max) {
      return value;
    }
    std::cerr << "Error: Value must be in the range [" << min << "..." << max
              << "].\n";
  }
}

std::string readString(const std::string &lable, int nestingLevel = 0) {
  const std::string indent(nestingLevel * 2, ' ');
  std::string value;
  std::cout << indent << "> " << lable << " = ", std::cin >> value;
  return value;
}

struct FullName {
  std::string firstName;
  std::string middleName;
  std::string lastName;

  void read(const std::string &lable) {
    std::cout << "> " << lable << ":\n";
    firstName = readString("First name", 1);
    middleName = readString("Middle name", 1);
    lastName = readString("Last name", 1);
  }
};

struct DateOfBirth {
  int day = 0;
  int mounth = 0;
  int year = 0;

  void read(const std::string &lable) {
    std::cout << "> " << lable << ":\n";
    day = readInt(0, 31, "Day");
    mounth = readInt(0, 12, "Mounth");
    year = readInt(1800, 2022, "Year");
  }
};

struct Book {
  std::string name;
  std::string authorsName;
};

class Reader {
private:
  FullName fullName;
  int readerTicketNumber = 0;
  DateOfBirth dateOfBirth;
  std::string phoneNumber;

public:
  Reader() {
    fullName.read("Full name");
    readerTicketNumber = readInt(1, 1000, "Number of tiket");
    dateOfBirth.read("Date fo birth");
    phoneNumber = readString("Phone number");
  }

  Reader(const FullName &fullname, int readerTicketNumber,
         const DateOfBirth &dateOfBirth, const std::string &phoneNumber)
      : fullName(fullname), readerTicketNumber(readerTicketNumber),
        dateOfBirth(dateOfBirth), phoneNumber(phoneNumber) {}

  void takeBook(int booksCount) const {
    std::cout << fullName.lastName << ' ' << fullName.firstName << ' '
              << fullName.middleName << "took " << std::to_string(booksCount)
              << " books\n";
  }

  void takeBook(const std::vector<std::string> books) const {
    std::cout << fullName.lastName << ' ' << fullName.firstName << ' '
              << fullName.middleName << "took books:";
    for (const auto &book : books) {
      std::cout << ' ' << book;
    }
    std::cout << '\n';
  }

  void takeBook(const std::vector<Book> books) const {
    std::cout << fullName.lastName << ' ' << fullName.firstName << ' '
              << fullName.middleName << "took books:";
    for (const auto &book : books) {
      std::cout << ' ' << book.name;
    }
    std::cout << '\n';
  }

  void returnBook(int booksCount) const {
    std::cout << fullName.lastName << ' ' << fullName.firstName << ' '
              << fullName.middleName << "returned "
              << std::to_string(booksCount) << " books\n";
  }

  void returnBook(const std::vector<std::string> books) const {
    std::cout << fullName.lastName << ' ' << fullName.firstName << ' '
              << fullName.middleName << "returned books:";
    for (const auto &book : books) {
      std::cout << ' ' << book;
    }
    std::cout << '\n';
  }

  void returnBook(const std::vector<Book> books) const {
    std::cout << fullName.lastName << ' ' << fullName.firstName << ' '
              << fullName.middleName << "returned books:";
    for (const auto &book : books) {
      std::cout << ' ' << book.name;
    }
    std::cout << '\n';
  }
};

int main() {
  std::vector<Reader> readers = {Reader(
      FullName{.firstName = "V.", .middleName = "V.", .lastName = "Petrov"}, 1,
      DateOfBirth{.day = 1, .mounth = 1, .year = 2000}, "+380131336754")};

  readers.front().takeBook(3);
  readers.front().returnBook(3);
  std::cout << '\n';

  readers.front().takeBook({"Adventures", "Dictionary", "Encyclopedia"});
  readers.front().returnBook({"Adventures", "Dictionary", "Encyclopedia"});
  std::cout << '\n';

  readers.front().takeBook(
      {Book{.name = "Adventures", .authorsName = "Unknown"},
       Book{.name = "Dictionary", .authorsName = "Unknown"},
       Book{.name = "Encyclopedia", .authorsName = "Unknown"}});
  readers.front().returnBook(
      {Book{.name = "Adventures", .authorsName = "Unknown"},
       Book{.name = "Dictionary", .authorsName = "Unknown"},
       Book{.name = "Encyclopedia", .authorsName = "Unknown"}});
  std::cout << '\n';
  return 0;
}