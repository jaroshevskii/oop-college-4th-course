#ifndef PHONE_H
#define PHONE_H

#include <string>
#include <vector>

/// Phone.
class Phone {
private:
  std::string number;
  std::string model;
  double width = 0.0;

public:
  Phone() = default;

  Phone(const std::string &number, const std::string& model, double width = 0.0);
  
  /// Writes the textual representations of the `Phone` into the standard
  /// output.
  void print() const;

  void receiveCall(const std::string &name) const;

  void receiveCall(const std::string &phoneName, const std::string &phoneNumber) const;

  const std::string &getNumber() const;

  void sendMessage(std::vector<std::string> phoneNumbers) const;
};

#endif // PHONE_H