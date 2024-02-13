#include <gtest/gtest.h>

#include "../include/BigInt.hpp"

TEST(BigInt, RelationalOps) {
  BigInt a("514321");
  BigInt b("12345");
  BigInt c("-12345");
  BigInt d("62345");

  EXPECT_TRUE(a > b);
  EXPECT_TRUE(b > c);
  EXPECT_TRUE(d > b);

  EXPECT_TRUE(b < a);
  EXPECT_TRUE(c < b);
  EXPECT_TRUE(b < d);

  EXPECT_TRUE(a == a);
  EXPECT_FALSE(b == c);
  EXPECT_TRUE(b != c);
}