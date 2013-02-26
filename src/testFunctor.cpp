#include "gtest/gtest.h"

#include "salve/Functor.hpp"
#include "salve/Comparable.hpp"

//////////////////////////////////

using namespace std;
using namespace salve;

TEST(TestFunctor, VectorInt) {
  FunctorDefinition<vector<int>, vector<int>>::verify();

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

template<typename A, typename Func>
auto map_(const std::vector<A>& orig,
          Func f) -> std::vector<decltype(f(orig[0]))> {
  std::vector<decltype(f(orig[0]))> rv;
  rv.reserve(orig.size());
  for (const A& a : orig) {
    rv.push_back(f(a));
  }
  return rv;
}

TEST(TestFunctor, VectorIntLambdaFunction) {
  const vector<int> ints = { 1, 2, 3 };

  const vector<int> out = map_(ints, [](int x) {return x + 1;});

  const vector<int> golden = { 2, 3, 4 };
  EXPECT_TRUE(equals(out, golden));

  // TODO: This next line should compile (shouldn't need to provide template
  // parameters or cast the lambda to a function). See:
  // http://stackoverflow.com/questions/7950680/how-can-i-pass-a-lambda-c11-into-a-templated-function
//  fmap([](int x){ return x + 1; }, ints);
}
