#include "gtest/gtest.h"

#include <boost/optional.hpp>

#include "salve/Seq.hpp"
#include "salve/Comparable.hpp"

///////////////////////////

using namespace std;
using namespace boost;
using namespace salve;

TEST(TestSeq, VectorInt) {
  vector<int> ints = { 1, 2, 3, 4 };

  EXPECT_TRUE(equals(headOption(ints), optional<int>(1)));

  vector<int> intsTail = { 2, 3, 4 };
  EXPECT_TRUE(equals(tail(ints), intsTail));

  vector<int> intsInit = { 1, 2, 3 };
  EXPECT_TRUE(equals(init(ints), intsInit));

  EXPECT_EQ(last(ints), 4);
}
