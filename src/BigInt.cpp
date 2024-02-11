#include "../include/BigInt.hpp"
#include <algorithm>

BigInt::BigInt(int t_int) {
  // BigInt(to_string(t_int))
}

BigInt::BigInt(const std::vector<int> &t_num) : num(t_num) {}

BigInt::BigInt(const std::string &t_string) {
  for (auto it = std::crbegin(t_string); it != std::crend(t_string); ++it) {
    if (*it >= '0' && *it <= '9') {
      num.emplace_back(*it - '0');
    }
  }
}

// auto BigInt::operator=(const std::string &t_string) const -> BigInt & {
//     return this(t_string);
// }

//  auto BigInt::operator=(int t_int) const -> BigInt & {
//     BigInt wrap(t_int);
//     return wrap;
// }

auto BigInt::operator+(const std::string &t_string) -> BigInt const {
    return *this + BigInt(t_string);
}

auto BigInt::operator+(int t_int) -> BigInt const {
  BigInt result;
  int carry = t_int;
  for (std::size_t i = 0; i < num.size() || carry; ++i) {
    int sum = carry;
    if (i < num.size())
      sum += num[i];
    carry = sum / base;
    sum %= base;
    result.num.emplace_back(sum);
  }
  return result;
}

auto BigInt::operator+(const BigInt &t_bigint) -> BigInt const {
  BigInt result;
  int carry = 0;
  const std::size_t size = std::max(num.size(), t_bigint.num.size());
  for (std::size_t i = 0; i < size || carry; ++i) {
    int sum = carry;
    if (i < num.size())
      sum += num[i];
    if (i < t_bigint.num.size())
      sum += t_bigint.num[i];
    carry = sum / base;
    sum %= base;
    result.num.emplace_back(sum);
  }
  return result;
}

// auto BigInt::operator-(int t_int) -> BigInt const {}

// auto BigInt::operator-(const std::string &t_string) -> BigInt const {}

// auto BigInt::operator/(int t_int) -> BigInt const {}

// auto BigInt::operator/(const std::string &t_string) -> BigInt const {}

// auto BigInt::operator*(const std::string &t_string) -> BigInt const {}

// auto BigInt::operator*(int t_int) -> BigInt const {}
