#include "Phone.h"
#include <iostream>

Phone::Phone(const std::string &number, const std::string &model, double width)
    : number(number), model(model), width(width) {}

void Phone::print() const {
  std::cout << model << ":\n"
            << "  Width:  " << width << '\n'
            << "  Number: " << number << "\n\n";
}

void Phone::receiveCall(const std::string &name) const {
  std::cout << "Cals " << name << "\n\n";
}

void Phone::receiveCall(const std::string &phoneName,
                        const std::string &phoneNumber) const {
  std::cout << "Cals " << phoneNumber << " (" << phoneName << ')' << "\n\n";
}

const std::string &Phone::getNumber() const { return number; }

void Phone::sendMessage(std::vector<std::string> phoneNumbers) const {
  std::cout << "Phone numbers:\n";

  if (phoneNumbers.size() == 0) {
    std::cout << "  Missing\n\n";
    return;
  }

  for (const auto &number : phoneNumbers) {
    std::cout << "  " << number << '\n';
  }
  std::cout << '\n';
}
