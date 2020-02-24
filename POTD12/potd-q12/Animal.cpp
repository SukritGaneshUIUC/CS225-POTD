// Animal.cpp
#include "Animal.h"

Animal::Animal() {
  type_ = "cat";
  food_ = "fish";
}
Animal::Animal(std::string t, std::string f) {
  type_ = t;
  food_ = f;
}
std::string Animal::getType() {
  return type_;
}
void Animal::setType(std::string t) {
  type_ = t;
}
std::string Animal::getFood() {
  return food_;
}
void Animal::setFood(std::string f) {
  food_ = f;
}
std::string Animal::print() {
  return "I am a " + type_ + ".";
}
