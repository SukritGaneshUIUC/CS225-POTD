// your code here
#include "Food.h"
#include "q5.h"

#include <iostream>

int main() {
  Food f;
  std::cout << "Quantity: " << f.get_quantity() << std::endl;
  increase_quantity(&f);
  std::cout << "Quantity: " << f.get_quantity() << std::endl;
}
