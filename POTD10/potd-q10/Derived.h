#pragma once
#include <string>
#include "Base.h"

class Derived : public Base::Base {
private:

public:
  std::string foo();
  virtual std::string bar();
  virtual ~Derived();
};
