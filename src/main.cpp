#include "../include/BigInt.hpp"

#include <iostream>

auto main() -> int {
  BigInt a("12345678901234567890");
  BigInt b("98765432109876543210");

  std::cout << "a + b = " << a - b << std::endl;

  return 0;
}