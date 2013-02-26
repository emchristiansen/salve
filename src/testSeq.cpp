#include "gtest/gtest.h"

#include "salve/Seq.hpp"
#include "salve/Comparable.hpp"

///////////////////////////

using namespace std;
using namespace salve;

TEST(TestSeq, VectorInt) {
  vector<int> ints = { 1, 2, 3, 4 };

  EXPECT_EQ(head(ints), 1);

  vector<int> intsTail = { 2, 3, 4 };
  EXPECT_TRUE(equals(tail(ints), intsTail));

  vector<int> intsInit = { 1, 2, 3 };
  EXPECT_TRUE(equals(init(ints), intsInit));

  EXPECT_EQ(last(ints), 4);
}
