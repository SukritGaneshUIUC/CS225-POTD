// your code here
#include "Bar.h"
#include <string>

using namespace potd;

Bar::Bar(std::string name) {
  f_ = new Foo::Foo(name);
}
Bar::Bar(Bar & copyBar) {
  f_ = new Foo::Foo(copyBar.get_name());
}
Bar::~Bar() {
  delete f_;
}
Bar & Bar::operator=(Bar & other) {
  delete this;
  return *(new Bar(other));
}
std::string Bar::get_name(){
  return f_->get_name();
}
