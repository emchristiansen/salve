#pragma once

#include <cmath>

#include "macros.hpp"

///////////////////////////

namespace salve {

using namespace std;

TYPECLASS(L2Distance, (A)) {
  virtual double l2Distance(const A& left, const A& right) = 0;
};

//////////////////////////////

EXPOSE(L2Distance, (A), l2Distance, (A)(A))

/////////////////////////////////

template<>
INSTANCE(L2Distance, (int)) {
  double l2Distance(const int& left, const int& right) override {
    return abs(left - right);
  }
};

template<typename ElementT>
INSTANCE(L2Distance, (vector<ElementT>)) {
  double l2Distance(
      const vector<ElementT>& left,
      const vector<ElementT>& right) override {
    assert(left.size() == right.size());
//    ASSERT_EQ(left.size(), right.size());

    auto leftElement = left.begin();
    auto rightElement = right.begin();
    double totalError = 0;
    for (; leftElement != left.end(); ++leftElement, ++rightElement) {
      totalError += pow(L2Distance<ElementT>().l2Distance(*leftElement, *rightElement), 2);
    }
    return sqrt(totalError);
  }
};

}  // namespace salve
