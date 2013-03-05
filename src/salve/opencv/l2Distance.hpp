#pragma once

#include <opencv2/opencv.hpp>

#include "salve/l2Distance.hpp"

////////////////////////////////////

namespace salve {

using namespace cv;

template<>
INSTANCE(L2Distance, (Mat)) {
  double l2Distance(const Mat& left, const Mat& right) override {
//    assert(left.rows == right.rows);
//    assert(left.cols == right.cols);
//    assert(left.channels() == right.channels());
//    assert(left.type() == right.type());

    return norm(left - right);
  }
};

///**
// * Anything which can be used to construct a Mat.
// */
//template<typename ConvertibleT>
//INSTANCE(L2Distance, (ConvertibleT)) {
//  typedef decltype(Mat(fakeInstance(ConvertibleT))) SFINAE;
//
//  double l2Distance(
//      const ConvertibleT& left,
//      const ConvertibleT& right) override {
//    const auto trash = fakeInstance(SFINAE);
//
//    return L2Distance<Mat>().l2Distance(Mat(left), Mat(right));
//  }
//};

}  // namespace salve
