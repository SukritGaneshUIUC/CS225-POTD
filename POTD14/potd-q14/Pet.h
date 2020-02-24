// Pet.h
#pragma once

#include "Animal.h"

#include <string>

class Pet : public Animal {
private:
  std::string name_;
  std::string owner_name_;
public:
  Pet();
  Pet(std::string t, std::string f, std::string n, std::string on);

  std::string print();

  std::string getName();
  std::string getOwnerName();
  void setName(std::string n);
  void setOwnerName(std::string on);
};
