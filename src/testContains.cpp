#include <type_traits>

#include "gtest/gtest.h"

#include "salve/Contains.hpp"

////////////////////////////////////////

using namespace salve;

TEST(TestContains, VectorContainsInt) {
  ContainsDefinition<vector<int>>::verify();

  static_assert(is_same<Contains<vector<int>>::ElementType, int>::value, "");
}
