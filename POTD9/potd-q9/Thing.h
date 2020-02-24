#pragma once

#include <string>

namespace potd {
  class Thing {
  public:
    Thing(int maxSize);
    Thing(const Thing & otherThing);
    Thing & operator=(const Thing & otherThing);
    ~Thing();

    int set_property(std::string name,std::string value);
    std::string get_property(std::string name);

    // std::string * getProperties() const;
    // std::string * getValues() const;
    // int getPropsCt() const;
    // int getPropsMax() const;

  private:

    void _copy(const Thing & otherThing);
    void _destroy();

    std::string *properties_;
    std::string *values_;
    int props_ct_;
    int props_max_;
  };
}
