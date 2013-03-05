#include "gtest/gtest.h"

#include <opencv2/opencv.hpp>

#include "salve/opencv/showable.hpp"

//////////////////////////////////

using namespace std;
using namespace cv;
using namespace salve;

TEST(TestOpenCVShowable, Mat) {
  const Matx13d matx(1, 2, 3);

  EXPECT_EQ(show(Mat(matx)), "[1, 2, 3]");
}
