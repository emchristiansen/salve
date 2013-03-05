#pragma once

#include <opencv2/opencv.hpp>

#include "salve/Showable.hpp"

////////////////////////////////////

namespace salve {

using namespace cv;

template<>
INSTANCE(Showable, (Mat)) {
  string show(const Mat& mat) {
    stringstream buffer;
    buffer << mat;
    return buffer.str();
  }
};

} // namespace salve

