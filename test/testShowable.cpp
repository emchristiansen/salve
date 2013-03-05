#include "gtest/gtest.h"

#include "salve/Showable.hpp"

/////////////////////////////////////

using namespace std;
using namespace salve;

TEST(TestShowable, String) {
  // TODO: Remove the need for this explicit type parameter.
  EXPECT_EQ("hi", show(string("hi")));
}

TEST(TestShowable, Int) {
  EXPECT_EQ("42", show(42));
}

TEST(TestShowable, Double) {
  EXPECT_EQ("1.2345", show(1.2345));
}

TEST(TestShowable, VectorInt) {
  const vector<int> ints = {1, 2, 3, 4};

  EXPECT_EQ("[1, 2, 3, 4]", show(ints));
}

TEST(TestShowable, VectorVectorInt) {
  const vector<int> ints = {1, 2};
  const vector<vector<int>> moreInts = {ints, ints};

  EXPECT_EQ("[[1, 2], [1, 2]]", show(moreInts));
}
