//
// Object-oriented programing (college 4th course)
// Practical work 6
//

#include <iostream>
#include <string>

class Publication {
private:
  std::string title;
  std::string author;
  double price;

public:
  Publication() = default;

  Publication(const std::string &title, const std::string &author, double price)
      : title(title), author(author), price(price) {}

  const std::string &getTitle() const { return title; }

  const std::string &getAuthor() const { return author; }

  double getPrice() const { return price; }

  void enterData() {
    std::cout << "> Title = ", std::getline(std::cin, title);
    std::cout << "> Author = ", std::getline(std::cin, author);
    std::cout << "> Price = ", std::cin >> price;
  }

  void displayData() const {
    std::cout << "Title: " << title << '\n'
              << "Author: " << author << '\n'
              << "Price: " << price << '\n';
  }
};

class Book : public Publication {
private:
  int pageCount = 0;

public:
  Book() = default;

  Book(const std::string &title, const std::string &author, double price,
       int pageCount)
      : Publication(title, author, price), pageCount(pageCount) {}

  int getPageCount() const { return pageCount; }

  void enterData() {
    Publication::enterData();
    std::cout << "> Page count = ", std::cin >> pageCount;
  }

  void displayData() const {
    Publication::displayData();
    std::cout << "Page count: " << pageCount << '\n';
  }

  bool isPriceLessThan200uah() const { return getPrice() < 200; }
};

class Record : public Publication {
private:
  /// Book recording time in minutes.
  int recordingTime = 0;

public:
  Record() = default;

  Record(const std::string &title, const std::string &author, double price,
         int recordingTime)
      : Publication(title, author, price), recordingTime(recordingTime) {}

  int getRecordingTime() const { return recordingTime; }

  void enterData() {
    Publication::enterData();
    std::cout << "> Recording time = ", std::cin >> recordingTime;
  }

  void displayData() const {
    Publication::displayData();
    std::cout << "Recording time: " << recordingTime << '\n';
  }

  int gerRecordingTimeInSeconds() const { return recordingTime * 60; }
};

int main() {
  const Publication publication("The Theater Of Dusk", "Lizbeth Gabriel", 500);

  publication.displayData();
  // Title: The Theater Of Dusk
  // Author: Lizbeth Gabriel
  // Price: 500

  std::cout << '\n';

  std::cout << publication.getTitle() << '\n';
  // Prints: "The Theater Of Dusk"
  std::cout << publication.getAuthor() << '\n';
  // Prints: "Lizbeth Gabriel"
  std::cout << publication.getPrice() << '\n';
  // Ptints: "500"

  std::cout << '\n';

  const Book book("Beneath the Willow", "Gemma Farrow", 600, 999);

  book.displayData();
  // Title: Beneath the Willow
  // Author: Gemma Farrow
  // Price: 600
  // Page count: 999

  std::cout << '\n';

  std::cout << book.getPageCount() << '\n';
  // Prints: "999"
  std::cout << std::boolalpha << book.isPriceLessThan200uah() << '\n';
  // Prints: "false"

  std::cout << '\n';

  const Record record("Sea Hearts", "Margo Lanagan", 700, 180);

  record.displayData();
  // Title: Sea Hearts
  // Author: Margo Lanagan
  // Price: 700
  // Recording time: 180

  std::cout << '\n';

  std::cout << record.getRecordingTime() << '\n';
  // Prints: "180"
  std::cout << record.gerRecordingTimeInSeconds() << '\n';
  // Prints: "10800"
  
  return 0;
}
