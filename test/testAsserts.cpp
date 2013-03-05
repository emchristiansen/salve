#include "gtest/gtest.h"

#include "salve/asserts.hpp"

//////////////////////////////////

using namespace std;
using namespace salve;

TEST(TestAsserts, ASSERT_NEAR_L2) {
  ASSERT_NEAR_L2(1, 2, 3);

  // This one will fail.
//  ASSERT_NEAR_L2(1, 10, 1);
}
