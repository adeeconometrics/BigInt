#ifndef __BIGINT_H__
#define __BIGINT_H__

#include <string>
#include <vector>
#include <ostream>

class BigInt {
public:
  BigInt() = default;
  BigInt(int t_int);
  BigInt(const std::vector<int> &t_num);
  BigInt(const std::string &t_string);

//   auto operator=(const std::string &t_string) const -> BigInt &;
  //  auto operator=(int t_int) const -> BigInt &;

  auto operator+(const BigInt &t_bigint) -> BigInt const;
  auto operator+(int t_int) -> BigInt const;
  auto operator+(const std::string &t_string) -> BigInt const;

//   auto operator-(int t_int) -> BigInt const;
//   auto operator-(const std::string &t_string) -> BigInt const;

//   auto operator*(int t_int) -> BigInt const;
//   auto operator*(const std::string &t_string) -> BigInt const;

//   auto operator/(int t_int) -> BigInt const;
//   auto operator/(const std::string &t_string) -> BigInt const;

  // constexpr auto operator>=()

friend auto operator<<(std::ostream& os, const BigInt& t_bi) -> std::ostream& {
  for (auto it = t_bi.num.rbegin(); it != t_bi.num.rend(); ++it) {
    os << *it;
  }
  return os;
}

private:
  std::vector<int> num;
  static constexpr int base = 10;
};

#endif // __BIGINT_H__