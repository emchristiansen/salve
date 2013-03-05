#include "gtest/gtest.h"

#include "salve/l2Distance.hpp"

//////////////////////////////////

using namespace std;
using namespace salve;

TEST(TestL2Distance, Int) {
  EXPECT_EQ(l2Distance(-4, 10), 14);
}

TEST(TestL2Distance, VectorInt) {
  const vector<int> left = {1, 2};
  const vector<int> right = {4, -2};

  l2Distance(left, right);

  EXPECT_EQ(l2Distance(left, right), 5);
}
