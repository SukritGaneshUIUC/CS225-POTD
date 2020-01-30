#pragma once

#include <string>

using namespace std;

class Pet {
 public:
  // Declare your constructors here!
  Pet();
  Pet(std::string n, int by, std::string t, std::string o);

  // Other member functions
  void setName(std::string newName);
  void setBY(int newBY);
  void setType(string newType);
  void setOwnerName(string newName);
  std::string getName();
  int getBY();
  std::string getType();
  std::string getOwnerName();

 private:
  std::string name;
  int birth_year;
  std::string type;
  std::string owner_name;
};
