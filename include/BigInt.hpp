#ifndef __BIGINT_H__
#define __BIGINT_H__

#include <algorithm>
#include <ostream>
#include <string>
#include <vector>

class BigInt {
public:
  BigInt() = default;
  BigInt(int t_int);
  BigInt(const std::vector<int> &t_num);
  BigInt(const std::string &t_string);
  BigInt(char const *t_string);

  //   auto operator=(const std::string &t_string) const -> BigInt &;
  //  auto operator=(int t_int) const -> BigInt &;

  auto operator+(BigInt t_bigint) -> BigInt;
  // auto operator+(int t_int) -> BigInt const;
  // auto operator+(const std::string &t_string) -> BigInt const;

  auto operator-(BigInt t_bigint) -> BigInt;
  //   auto operator-(int t_int) -> BigInt const;
  //   auto operator-(const std::string &t_string) -> BigInt const;

  auto operator-() -> BigInt;
  // auto operator*(const BigInt &t_bigint) -> BigInt const;
  //   auto operator*(int t_int) -> BigInt const;
  //   auto operator*(const std::string &t_string) -> BigInt const;

  // auto operator/(const BigInt &t_bigint) -> BigInt const;
  //   auto operator/(int t_int) -> BigInt const;
  //   auto operator/(const std::string &t_string) -> BigInt const;

  auto operator>(const BigInt &rhs) -> bool const;
  auto operator<(const BigInt &rhs) -> bool const;
  auto operator==(const BigInt &rhs) -> bool const;
  auto operator!=(const BigInt &rhs) -> bool const;
  auto operator>=(const BigInt &rhs) -> bool const;
  auto operator<=(const BigInt &rhs) -> bool const;

  friend auto operator<<(std::ostream &os, const BigInt &t_bi)
      -> std::ostream & {
    if (t_bi.is_negative)
      os << "-";
    for (auto it = std::crbegin(t_bi.num); it != std::crend(t_bi.num); ++it) {
      os << *it;
    }
    return os;
  }

  operator std::string() const;

private:
  auto shift_left(std::size_t places) -> BigInt const;

private:
  bool is_negative{false};
  std::vector<int> num;
  static constexpr int base = 10;
};

#endif // __BIGINT_H__