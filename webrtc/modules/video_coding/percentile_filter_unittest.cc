/*
 *  Copyright 2016 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include <algorithm>

#include "testing/gtest/include/gtest/gtest.h"
#include "webrtc/base/constructormagic.h"
#include "webrtc/modules/video_coding/percentile_filter.h"

namespace webrtc {

class PercentileFilterTest : public ::testing::TestWithParam<float> {
 public:
  PercentileFilterTest() : filter_(GetParam()) {
    // Make sure the tests are deterministic by seeding with a constant.
    srand(42);
  }

 protected:
  PercentileFilter filter_;

 private:
  RTC_DISALLOW_COPY_AND_ASSIGN(PercentileFilterTest);
};

INSTANTIATE_TEST_CASE_P(PercentileFilterTests,
                        PercentileFilterTest,
                        ::testing::Values(0.0f, 0.1f, 0.5f, 0.9f, 1.0f));

TEST(PercentileFilterTest, MinFilter) {
  PercentileFilter filter(0.0f);
  filter.Insert(4);
  EXPECT_EQ(4, filter.GetPercentileValue());
  filter.Insert(3);
  EXPECT_EQ(3, filter.GetPercentileValue());
}

TEST(PercentileFilterTest, MaxFilter) {
  PercentileFilter filter(1.0f);
  filter.Insert(3);
  EXPECT_EQ(3, filter.GetPercentileValue());
  filter.Insert(4);
  EXPECT_EQ(4, filter.GetPercentileValue());
}

TEST_P(PercentileFilterTest, EmptyFilter) {
  EXPECT_EQ(0, filter_.GetPercentileValue());
  filter_.Insert(3);
  filter_.Erase(3);
  EXPECT_EQ(0, filter_.GetPercentileValue());
}

TEST_P(PercentileFilterTest, EraseNonExistingElement) {
  filter_.Erase(3);
  EXPECT_EQ(0, filter_.GetPercentileValue());
  filter_.Insert(4);
  filter_.Erase(3);
  EXPECT_EQ(4, filter_.GetPercentileValue());
}

TEST_P(PercentileFilterTest, DuplicateElements) {
  filter_.Insert(3);
  filter_.Insert(3);
  filter_.Erase(3);
  EXPECT_EQ(3, filter_.GetPercentileValue());
}

TEST_P(PercentileFilterTest, InsertAndEraseTenValuesInRandomOrder) {
  int64_t zero_to_nine[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  // The percentile value of the ten values above.
  const int64_t expected_value = static_cast<int64_t>(GetParam() * 9);

  // Insert two sets of |zero_to_nine| in random order.
  for (int i = 0; i < 2; ++i) {
    std::random_shuffle(zero_to_nine, zero_to_nine + 10);
    for (int64_t value : zero_to_nine)
      filter_.Insert(value);
    // After inserting a full set of |zero_to_nine|, the percentile should
    // stay constant.
    EXPECT_EQ(expected_value, filter_.GetPercentileValue());
  }

  // Insert and erase sets of |zero_to_nine| in random order a few times.
  for (int i = 0; i < 3; ++i) {
    std::random_shuffle(zero_to_nine, zero_to_nine + 10);
    for (int64_t value : zero_to_nine)
      filter_.Erase(value);
    EXPECT_EQ(expected_value, filter_.GetPercentileValue());

    std::random_shuffle(zero_to_nine, zero_to_nine + 10);
    for (int64_t value : zero_to_nine)
      filter_.Insert(value);
    EXPECT_EQ(expected_value, filter_.GetPercentileValue());
  }
}

}  // namespace webrtc
