#include <gtest/gtest.h>

#include "../include/BigInt.hpp"

TEST(BigInt, RelationalOps) {
  BigInt a("514321");
  BigInt b("12345");
  const BigInt c("-12345");
  const BigInt d("62345");

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

TEST(BigInt, Arithmetics) {
  const BigInt a("-12345");
  const BigInt b("12345");
  const BigInt c("0");
  const BigInt d("24690");

  EXPECT_EQ(a + b, c);
  EXPECT_EQ(a + a, -d);
  EXPECT_EQ(b + b, d);
}