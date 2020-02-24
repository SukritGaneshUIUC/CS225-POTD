// your code here
#pragma once
#include "Foo.h"

namespace potd{
  class Bar {
  private:
    Foo * f_;
  public:
    Bar(std::string name);
    Bar(Bar & copyBar);
    ~Bar();
    Bar & operator=(Bar & other);
    std::string get_name();
  };
}
