// Your code here!
#include "Thing.h"
#include <iostream>

namespace potd {

  Thing::Thing(int maxSize) {
    properties_ = new std::string[maxSize];
    values_ = new std::string[maxSize];
    props_ct_ = 0;
    props_max_ = maxSize;
  }
  Thing::Thing(const Thing & otherThing) {
    _copy(otherThing);
  }
  Thing & Thing::operator=(const Thing & otherThing) {
    _destroy();
    std::cout << "destroyed" << std::endl;
    _copy(otherThing);
    std::cout << "copied" << std::endl;
    return *this;
  }
  Thing::~Thing() {
    _destroy();
  }

  int Thing::set_property(std::string name, std::string value) {
    // check if value is already there
    for (int i = 0; i < props_ct_; i++) {
        if (properties_[i] == name) {
          values_[i] = value;
          return i;
        }
    }

    // if property doesn't exist and properties is full,
    // return -1
    if (props_ct_ >= props_max_) {
      return -1;
    }

    // otherwise, add a property
    properties_[props_ct_] = name;
    values_[props_ct_] = value;
    props_ct_ ++;
    return props_ct_ - 1;
  }

  std::string Thing::get_property(std::string name) {
    for (int i = 0; i < props_ct_; i++) {
        if (properties_[i] == name) {
          return values_[i];
        }
    }
    return "";
  }

  void Thing::_copy(const Thing & otherThing) {
    props_max_ = otherThing.props_max_;
    props_ct_ = otherThing.props_ct_;
    properties_ = new std::string[props_max_];
    values_ = new std::string[props_max_];

    for (int i = 0; i < props_ct_; i++) {
      properties_[i] = otherThing.properties_[i];
      values_[i] = otherThing.values_[i];
    }
  }
  void Thing::_destroy() {
    delete[] properties_;
    delete[] values_;
  }

  // std::string * Thing::getProperties() const {
  //   return properties_;
  // }
  //
  // std::string * Thing::getValues() const {
  //   return values_;
  // }
  //
  // int Thing::getPropsCt() const {
  //   return props_ct_;
  // }
  //
  // int Thing::getPropsMax() const {
  //   return props_max_;
  // }

}
