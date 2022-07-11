/*
 *  Copyright (c) 2015 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */
#ifndef WEBRTC_TEST_FAKE_TEXTURE_FRAME_H_
#define WEBRTC_TEST_FAKE_TEXTURE_FRAME_H_

#include "webrtc/base/checks.h"
#include "webrtc/common_video/include/video_frame_buffer.h"
#include "webrtc/video_frame.h"

namespace webrtc {
namespace test {

class FakeNativeHandle {
 public:
  static VideoFrame CreateFrame(FakeNativeHandle* native_handle,
                                int width,
                                int height,
                                uint32_t timestamp,
                                int64_t render_time_ms,
                                VideoRotation rotation);
};

class FakeNativeHandleBuffer : public NativeHandleBuffer {
 public:
  FakeNativeHandleBuffer(void* native_handle, int width, int height)
      : NativeHandleBuffer(native_handle, width, height) {}

  ~FakeNativeHandleBuffer() {
    delete reinterpret_cast<FakeNativeHandle*>(native_handle_);
  }

 private:
  rtc::scoped_refptr<VideoFrameBuffer> NativeToI420Buffer() override {
    rtc::scoped_refptr<VideoFrameBuffer> buffer(
        I420Buffer::Create(width_, height_));
    int half_height = (height_ + 1) / 2;
    int half_width = (width_ + 1) / 2;
    memset(buffer->MutableDataY(), 0, height_ * width_);
    memset(buffer->MutableDataU(), 0, half_height * half_width);
    memset(buffer->MutableDataV(), 0, half_height * half_width);
    return buffer;
  }
};

}  // namespace test
}  // namespace webrtc
#endif  //  WEBRTC_TEST_FAKE_TEXTURE_FRAME_H_
