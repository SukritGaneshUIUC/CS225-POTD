#pragma once
#include <string>

class Base {
private:

public:
  std::string foo();
  virtual std::string bar();
  virtual ~Base();
};
