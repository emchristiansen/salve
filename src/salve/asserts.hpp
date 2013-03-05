#pragma once

#include <stdexcept>
#include <iostream>

#include "Showable.hpp"
#include "l2Distance.hpp"

///////////////////////////////////////

namespace salve {

#define ASSERT_NEAR_L2(left, right, epsilon) \
  if (l2Distance(left, right) >= epsilon) { \
    PRINTLN(string("ASSERT_NEAR_L2 failed:")); \
    PRINTLN("  Left is: " + string(#left) + " => " + show(left)); \
    PRINTLN("  Right is: " + string(#right) + " => " + show(right)); \
    PRINTLN("  Epsilon is: " + show(epsilon)); \
    PRINTLN("  Actual distance is: " + show(l2Distance(left, right))); \
    throw std::runtime_error("ASSERT_NEAR_L2 failed"); \
  }

}  // namespace salve



//ASSERT_NEAR_L2(1, 1, 1);
