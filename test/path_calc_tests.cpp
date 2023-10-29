#include <gtest/gtest.h>

#include "path.h"

TEST(example, add) {
  double res;
  res = 3.0;
  ASSERT_NEAR(res, 3.0, 1.0e-11);
}