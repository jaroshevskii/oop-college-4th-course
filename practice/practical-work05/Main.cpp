#include <iostream>
#include <string>
#include <vector>

class Text {
private:
  std::vector<std::string> strings;
  int maxRowLenght = 0;

public:
  Text() {
    std::cout << "> Rows count = ";
    int rowsCount = 0;
    std::cin >> rowsCount;

    std::cout << "> Max row lenght = ";
    std::cin >> maxRowLenght;

    for (int i = 0; i < rowsCount; ++i) {
      std::string input;
      while (true) {
        std::cout << "> ";
        std::cin.get();
        std::getline(std::cin, input);

        if (input.size() <= maxRowLenght) {
          break;
        }

        std::cout << "Error: The number of characters must not exceed "
                  << maxRowLenght << '.';
      }
      strings.push_back(input);
    }
  }

  int getRowsCount() const { return strings.size(); }

  void insert(int index, const std::string &value) {
    if (value.size() > maxRowLenght) {
      std::cout << "Error: The number of characters must not exceed "
                << maxRowLenght << '.';
      return;
    }

    strings.insert(strings.begin() + index, value);
  }

  void add(int index, const std::string &value) {
    if (value.size() > maxRowLenght) {
      std::cout << "Error: The number of characters must not exceed "
                << maxRowLenght << '.';
      return;
    }

    strings.at(index) = value;
  }

  void print() const {
    for (const auto &string : strings) {
      std::cout << string << '\n';
    }
    std::cout << '\n';
  }

  int search(const std::string &value) const {
    for (int i = 0; i < strings.size(); ++i) {
      if (strings[i] == value) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  Text textExample;
  textExample.print();

  std::cout << "Rows count: " << textExample.getRowsCount() << "\n\n";

  textExample.insert(3, "This is instrted row!");
  textExample.add(3, " OMG...");

  std::cout << "Shearched index: " << textExample.search("XXX");
  return 0;
}