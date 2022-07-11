/*
 *  Copyright 2004 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_PC_RTCPMUXFILTER_H_
#define WEBRTC_PC_RTCPMUXFILTER_H_

#include "webrtc/base/basictypes.h"
#include "webrtc/p2p/base/sessiondescription.h"

namespace cricket {

// RTCP Muxer, as defined in RFC 5761 (http://tools.ietf.org/html/rfc5761)
class RtcpMuxFilter {
 public:
  RtcpMuxFilter();

  // Whether the filter is active, i.e. has RTCP mux been properly negotiated.
  bool IsActive() const;

  // Make the filter active, regardless of the current state.
  void SetActive();

  // Specifies whether the offer indicates the use of RTCP mux.
  bool SetOffer(bool offer_enable, ContentSource src);

  // Specifies whether the provisional answer indicates the use of RTCP mux.
  bool SetProvisionalAnswer(bool answer_enable, ContentSource src);

  // Specifies whether the answer indicates the use of RTCP mux.
  bool SetAnswer(bool answer_enable, ContentSource src);

  // Determines whether the specified packet is RTCP.
  bool DemuxRtcp(const char* data, int len);

 private:
  bool ExpectOffer(bool offer_enable, ContentSource source);
  bool ExpectAnswer(ContentSource source);
  enum State {
    // RTCP mux filter unused.
    ST_INIT,
    // Offer with RTCP mux enabled received.
    // RTCP mux filter is not active.
    ST_RECEIVEDOFFER,
    // Offer with RTCP mux enabled sent.
    // RTCP mux filter can demux incoming packets but is not active.
    ST_SENTOFFER,
    // RTCP mux filter is active but the sent answer is only provisional.
    // When the final answer is set, the state transitions to ST_ACTIVE or
    // ST_INIT.
    ST_SENTPRANSWER,
    // RTCP mux filter is active but the received answer is only provisional.
    // When the final answer is set, the state transitions to ST_ACTIVE or
    // ST_INIT.
    ST_RECEIVEDPRANSWER,
    // Offer and answer set, RTCP mux enabled. It is not possible to de-activate
    // the filter.
    ST_ACTIVE
  };
  State state_;
  bool offer_enable_;
};

}  // namespace cricket

#endif  // WEBRTC_PC_RTCPMUXFILTER_H_
