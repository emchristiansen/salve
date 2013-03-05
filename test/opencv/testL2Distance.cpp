#include "gtest/gtest.h"

#include <opencv2/opencv.hpp>

#include "salve/opencv/l2Distance.hpp"

//////////////////////////////////

using namespace std;
using namespace cv;
using namespace salve;

TEST(TestOpenCVL2Distance, Mat) {
  const Mat left = Mat::zeros(2, 3, CV_64F);
  const Mat right = Mat::ones(2, 3, CV_64F);

  EXPECT_EQ(l2Distance(left, left), 0);
  EXPECT_EQ(l2Distance(left, right), sqrt(6));
}

