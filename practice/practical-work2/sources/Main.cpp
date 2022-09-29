#include "Phone.h"
#include <iostream>
#include <string>

int main() {
  const Phone iPhone("123123123", "4S", 123.0);
  iPhone.print();
  iPhone.receiveCall("Tim");
  iPhone.receiveCall("iPhone", iPhone.getNumber());
  iPhone.sendMessage({"123123123", "456456456"});

  std::cout << std::string(80, '-') << "\n\n";

  const Phone asus("456456456", "Zen 4", 456.0);
  asus.print();
  asus.receiveCall("Alex");
  asus.receiveCall("Asus", asus.getNumber());
  asus.sendMessage({"123123123"});

  std::cout << std::string(80, '-') << "\n\n";

  const Phone sony("789789789", "Mark 2", 789.0);
  sony.print();
  sony.receiveCall("Nika");
  asus.receiveCall("Sony", asus.getNumber());
  asus.sendMessage({});

  return 0;
}