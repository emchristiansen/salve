#include "gtest/gtest.h"

#include "salve/CanBuildFrom.hpp"

///////////////////////////

using namespace salve;

TEST(TestCanBuildFrom, VectorIntToString) {
  CanBuildFromDefinition<vector<int>, string>::verify();

  static_assert(is_same<CanBuildFrom<vector<int>, double>::ToT, vector<double>>::value, "");
}
