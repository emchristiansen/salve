#include "gtest/gtest.h"

#include "salve/Comparable.hpp"

/////////////////////////////////

using namespace salve;

TEST(TestComparable, Int) {
  ComparableDefinition<int>::verify();

  EXPECT_TRUE(equals(1, 1));
  EXPECT_FALSE(equals(1, 2));
}

TEST(TestComparable, VectorInt) {
  ComparableDefinition<vector<int>>::verify();

  const vector<int> left = {1, 2};
  const vector<int> right = {3, 4};

  EXPECT_TRUE(equals(left, left));
  EXPECT_FALSE(equals(left, right));
}

