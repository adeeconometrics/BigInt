#include "../include/BigInt.hpp"

#include <algorithm>
#include <string>

BigInt::BigInt(int t_int) : BigInt(std::to_string(t_int)) {}

BigInt::BigInt(const std::vector<int> &t_num) : num(t_num) {}

BigInt::BigInt(const std::string &t_string) {
  auto it = std::cbegin(t_string);
  if (*it == '-') {
    is_negative = true;
    ++it;
  }

  for (; it != std::cend(t_string); ++it) {
    if (*it >= '0' && *it <= '9') {
      num.emplace_back(*it - '0');
    }
  }
}

BigInt::BigInt(char const *t_string) : BigInt(std::string(t_string)) {}

// auto BigInt::operator=(const std::string &t_string) const -> BigInt & {
//     return this(t_string);
// }

//  auto BigInt::operator=(int t_int) const -> BigInt & {
//     BigInt wrap(t_int);
//     return wrap;
// }

// auto BigInt::operator+(const std::string &t_string) -> BigInt const {
//   return *this + BigInt(t_string);
// }

// auto BigInt::operator+(int t_int) -> BigInt const {
//   BigInt result;
//   int carry = t_int;
//   for (std::size_t i = 0; i < num.size() || carry; ++i) {
//     int sum = carry;
//     if (i < num.size())
//       sum += num[i];
//     carry = sum / base;
//     sum %= base;
//     result.num.emplace_back(sum);
//   }
//   return result;
// }

auto BigInt::operator+(BigInt t_bigint) -> BigInt {
  if (is_negative && !t_bigint.is_negative)
    return t_bigint - (-*this);
  if (!is_negative && t_bigint.is_negative)
    return *this - (-t_bigint);
  if (is_negative && t_bigint.is_negative)
    return -((-*this) + (-t_bigint));

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

auto BigInt::operator-(BigInt t_bigint) -> BigInt {
  if (is_negative && !t_bigint.is_negative)
    return -((-*this) + t_bigint);
  if (!is_negative && t_bigint.is_negative)
    return *this + (-t_bigint);
  if (is_negative && t_bigint.is_negative)
    return t_bigint - *this;

  if (*this > t_bigint)
    return -(t_bigint - *this);

  BigInt result;
  int borrow = 0;
  for (std::size_t i = 0; i < num.size(); ++i) {
    int diff = num[i] - borrow;
    if (i < t_bigint.num.size())
      diff -= t_bigint.num[i];
    if (diff < 0) {
      diff += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }
    result.num.emplace_back(diff);
  }
  // Remove leading zeros
  while (result.num.size() > 1 && result.num.back() == 0) {
    result.num.pop_back();
  }
  return result;
}

// auto BigInt::operator-(int t_int) -> BigInt const {}

// auto BigInt::operator-(const std::string &t_string) -> BigInt const {}

auto BigInt::operator-() -> BigInt {
  this->is_negative = !this->is_negative;
  return *this;
}

// auto BigInt::operator*(const BigInt &t_bigint) -> BigInt const {
//   BigInt result;
//   for (std::size_t i = 0; i < num.size(); ++i) {
//     result = result + (t_bigint * num[i]).shift_left(i);
//   }
//   return result;
// }

// auto BigInt::operator*(const std::string &t_string) -> BigInt const {}

// auto BigInt::operator*(int t_int) -> BigInt const {}

// auto BigInt::operator/(const BigInt &t_bigint) -> BigInt const {
//   BigInt result, remainder;
//   for (std::size_t i = num.size() - 1; i >= 0; --i) {
//     remainder = remainder * base + num[i];
//     int quotient = 0;
//     while (remainder >= t_bigint) {
//       remainder = remainder - t_bigint;
//       quotient++;
//     }
//     result.num.emplace_back(quotient);
//   }
//   std::reverse(result.num.begin(), result.num.end());
//   // Remove leading zeros
//   while (result.num.size() > 1 && result.num.back() == 0) {
//     result.num.pop_back();
//   }
//   return result;
// }

// auto BigInt::operator/(int t_int) -> BigInt const {}

// auto BigInt::operator/(const std::string &t_string) -> BigInt const {}

auto BigInt::operator>(const BigInt &rhs) -> bool const {
  if (num.size() != rhs.num.size())
    return num.size() > rhs.num.size();
  // if (is_negative != rhs.is_negative)
  //   return !is_negative;

  const std::size_t len = num.size();
  for (std::size_t i = len - 1; i >= 0; --i) {
    if (num[i] != rhs.num[i])
      return num[i] > rhs.num[i];
  }
  return false;
}

auto BigInt::operator<(const BigInt &rhs) -> bool const {
  if (num.size() != rhs.num.size())
    return num.size() < rhs.num.size();
  // if (is_negative != rhs.is_negative)
  //   return is_negative;

  const std::size_t len = num.size();
  for (std::size_t i = len - 1; i >= 0; --i) {
    if (num[i] != rhs.num[i])
      return num[i] < rhs.num[i];
  }
  return false;
}

auto BigInt::operator==(const BigInt &rhs) -> bool const {
  return std::equal(std::cbegin(num), std::cend(num), std::cbegin(rhs.num));
}

auto BigInt::operator!=(const BigInt &rhs) -> bool const {
  return !(*this == rhs);
}

auto BigInt::operator>=(const BigInt &rhs) -> bool const {
  return (*this) > rhs || (*this) == rhs;
}

auto BigInt::operator<=(const BigInt &rhs) -> bool const {
  return (*this) < rhs || (*this) == rhs;
}

BigInt::operator std::string() const {
  std::string result;
  std::for_each(std::cbegin(num), std::cend(num),
                [&result](int element) { result += std::to_string(element); });
  return result;
}

auto BigInt::shift_left(std::size_t places) -> BigInt const {
  BigInt result(*this);
  result.num.insert(result.num.begin(), places, 0);
  return result;
}
