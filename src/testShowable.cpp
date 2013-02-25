#include "gtest/gtest.h"

#include "salve/Showable.hpp"

/////////////////////////////////////

using namespace std;
using namespace salve;

TEST(TestShowable, String) {
  ShowableDefinition<string>::verify();

  // TODO: Remove the need for this explicit type parameter.
  EXPECT_EQ("hi", show<string>("hi"));
}

TEST(TestShowable, Int) {
  ShowableDefinition<int>::verify();

  EXPECT_EQ("42", show(42));
}

TEST(TestShowable, Double) {
  ShowableDefinition<double>::verify();

  EXPECT_EQ("1.2345", show(1.2345));
}

TEST(TestShowable, VectorInt) {
  ShowableDefinition<vector<int>>::verify();

  const vector<int> ints = {1, 2, 3, 4};

  EXPECT_EQ("[1, 2, 3, 4]", show(ints));
}

TEST(TestShowable, VectorVectorInt) {
  ShowableDefinition<vector<vector<int>>>::verify();

  const vector<int> ints = {1, 2};
  const vector<vector<int>> moreInts = {ints, ints};

  EXPECT_EQ("[[1, 2], [1, 2]]", show(moreInts));
}
