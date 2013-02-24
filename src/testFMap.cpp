#include <iostream>

#include "gtest/gtest.h"

#include "FCPP.hpp"

template<typename A, typename S = Showable<A>>
void foo(const A& a) {
  cout << S::show(a) << endl;
}

TEST(sample_test_case, sample_test) {
  auto x = 1;

  function<int(int)> f = [x](int n) {return n + 1;};

  const vector<int> input = { 1, 2, 3 };
  const auto output = fmap(input, f);

  for (auto i : output)
    cout << i << endl;

  cout << equals(1, 1) << endl;
  cout << equals(input, input) << endl;

  cout << Showable<int>::show(42) << endl;

  cout << Showable<vector<int>>::show(input) << endl;

  vector<double> doubles = { 1.1, 2.2 };

  cout << show(doubles) << endl;

  foo(1);

  EXPECT_EQ(1, 1);
}
