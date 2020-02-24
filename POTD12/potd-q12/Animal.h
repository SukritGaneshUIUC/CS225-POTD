// Animal.h
#pragma once

#include <string>

class Animal {
private:
  std::string type_;
  std::string food_;
public:
  Animal();
  Animal(std::string t, std::string f);
  virtual std::string getType();
  virtual void setType(std::string t);
  virtual std::string getFood();
  virtual void setFood(std::string f);
  virtual std::string print();
};
