// Your code here
#include "Food.h"

Food::Food() {
  name_ = "";
  quantity_ = 0;
}

std::string Food::get_name() {
  return name_;
}
void Food::set_name(std::string newName) {
  name_ = newName;
}
int Food::get_quantity() {
  return quantity_;
}
void Food::set_quantity(int newQuantity) {
  quantity_ = newQuantity;
}
