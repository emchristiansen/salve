#include "gtest/gtest.h"

#include <type_traits>

#include "salve/Functor.hpp"
#include "salve/Comparable.hpp"

//////////////////////////////////

using namespace std;
using namespace salve;

TEST(TestFunctor, VectorInt) {
  auto add1 = [](int x){ return x + 1; };
  FunctorDefinition<vector<int>, decltype(add1)>::verify();

  const vector<int> ints = { 1, 2, 3 };

  const function<vector<int>(int)> wrap = [](int n) {
    vector<int> out = {n};
    return out;
  };

  const vector<vector<int>> wrapped = fmap(wrap, ints);

  const vector<int> wrapped1 = { 1 };
  const vector<int> wrapped2 = { 2 };
  const vector<int> wrapped3 = { 3 };
  const vector<vector<int>> golden = { wrapped1, wrapped2, wrapped3 };

  EXPECT_TRUE(equals(wrapped, golden));
}

TEST(TestFunctor, VectorIntLambdaFunction) {
  const vector<int> ints = { 1, 2, 3 };

  const vector<int> out = fmap([](int x) {return x + 1;}, ints);

  const vector<int> golden = { 2, 3, 4 };
  EXPECT_TRUE(equals(out, golden));
}
