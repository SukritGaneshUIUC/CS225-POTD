// Pet.cpp
#include "Pet.h"

Pet::Pet(): Animal("cat", "fish") {
  name_ = "Fluffy";
  owner_name_ = "Cinda";
}
Pet::Pet(std::string t, std::string f, std::string n, std::string on)
  : Animal(t, f) {
  name_ = n;
  owner_name_ = on;
}

std::string Pet::print() {
  return "My name is " + name_;
}

std::string Pet::getName() {
  return name_;
}
std::string Pet::getOwnerName() {
  return owner_name_;
}
void Pet::setName(std::string n) {
  name_ = n;
}
void Pet::setOwnerName(std::string on) {
  owner_name_ = on;
}
