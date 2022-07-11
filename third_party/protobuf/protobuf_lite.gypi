# Copyright 2013 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

{
  'sources': [
    'src/google/protobuf/arena.cc',
    'src/google/protobuf/arena.h',
    'src/google/protobuf/arenastring.cc',
    'src/google/protobuf/arenastring.h',
    'src/google/protobuf/extension_set.cc',
    'src/google/protobuf/extension_set.h',
    'src/google/protobuf/generated_message_util.cc',
    'src/google/protobuf/generated_message_util.h',
    'src/google/protobuf/io/coded_stream.cc',
    'src/google/protobuf/io/coded_stream.h',
    'src/google/protobuf/io/coded_stream_inl.h',
    'src/google/protobuf/io/zero_copy_stream.cc',
    'src/google/protobuf/io/zero_copy_stream.h',
    'src/google/protobuf/io/zero_copy_stream_impl_lite.cc',
    'src/google/protobuf/io/zero_copy_stream_impl_lite.h',
    'src/google/protobuf/map.h',
    'src/google/protobuf/map_entry_lite.h',
    'src/google/protobuf/map_field_lite.h',
    'src/google/protobuf/map_type_handler.h',
    'src/google/protobuf/message_lite.cc',
    'src/google/protobuf/message_lite.h',
    'src/google/protobuf/repeated_field.cc',
    'src/google/protobuf/repeated_field.h',
    'src/google/protobuf/stubs/atomicops.h',
    'src/google/protobuf/stubs/atomicops_internals_arm64_gcc.h',
    'src/google/protobuf/stubs/atomicops_internals_arm_gcc.h',
    'src/google/protobuf/stubs/atomicops_internals_arm_qnx.h',
    'src/google/protobuf/stubs/atomicops_internals_atomicword_compat.h',
    'src/google/protobuf/stubs/atomicops_internals_generic_gcc.h',
    'src/google/protobuf/stubs/atomicops_internals_macosx.h',
    'src/google/protobuf/stubs/atomicops_internals_mips_gcc.h',
    'src/google/protobuf/stubs/atomicops_internals_pnacl.h',
    'src/google/protobuf/stubs/atomicops_internals_power.h',
    'src/google/protobuf/stubs/atomicops_internals_ppc_gcc.h',
    'src/google/protobuf/stubs/atomicops_internals_solaris.h',
    'src/google/protobuf/stubs/atomicops_internals_tsan.h',
    'src/google/protobuf/stubs/atomicops_internals_x86_gcc.cc',
    'src/google/protobuf/stubs/atomicops_internals_x86_gcc.h',
    'src/google/protobuf/stubs/atomicops_internals_x86_msvc.cc',
    'src/google/protobuf/stubs/atomicops_internals_x86_msvc.h',
    'src/google/protobuf/stubs/atomic_sequence_num.h',
    'src/google/protobuf/stubs/bytestream.cc',
    'src/google/protobuf/stubs/bytestream.h',
    'src/google/protobuf/stubs/callback.h',
    'src/google/protobuf/stubs/casts.h',
    'src/google/protobuf/stubs/common.cc',
    'src/google/protobuf/stubs/common.h',
    'src/google/protobuf/stubs/fastmem.h',
    'src/google/protobuf/stubs/hash.h',
    'src/google/protobuf/stubs/int128.cc',
    'src/google/protobuf/stubs/int128.h',
    'src/google/protobuf/stubs/logging.h',
    'src/google/protobuf/stubs/macros.h',
    'src/google/protobuf/stubs/map_util.h',
    'src/google/protobuf/stubs/mutex.h',
    'src/google/protobuf/stubs/once.cc',
    'src/google/protobuf/stubs/once.h',
    'src/google/protobuf/stubs/platform_macros.h',
    'src/google/protobuf/stubs/port.h',
    'src/google/protobuf/stubs/scoped_ptr.h',
    'src/google/protobuf/stubs/shared_ptr.h',
    'src/google/protobuf/stubs/status.cc',
    'src/google/protobuf/stubs/status.h',
    'src/google/protobuf/stubs/status_macros.h',
    'src/google/protobuf/stubs/statusor.cc',
    'src/google/protobuf/stubs/statusor.h',
    'src/google/protobuf/stubs/stl_util.h',
    'src/google/protobuf/stubs/stringpiece.cc',
    'src/google/protobuf/stubs/stringpiece.h',
    'src/google/protobuf/stubs/stringprintf.cc',
    'src/google/protobuf/stubs/stringprintf.h',
    'src/google/protobuf/stubs/structurally_valid.cc',
    'src/google/protobuf/stubs/strutil.cc',
    'src/google/protobuf/stubs/strutil.h',
    'src/google/protobuf/stubs/template_util.h',
    'src/google/protobuf/stubs/type_traits.h',
    'src/google/protobuf/stubs/time.cc',
    'src/google/protobuf/stubs/time.h',
    'src/google/protobuf/wire_format_lite.cc',
    'src/google/protobuf/wire_format_lite.h',
    'src/google/protobuf/wire_format_lite_inl.h',
  ],
  'include_dirs': [
    'src',
  ],
  'defines': [
    # This macro must be defined to suppress the use of dynamic_cast<>,
    # which requires RTTI.
    'GOOGLE_PROTOBUF_NO_RTTI',

    'GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER',
    'HAVE_PTHREAD',
  ],
  'direct_dependent_settings': {
    'include_dirs': [
      'src',
    ],
    'defines': [
      'GOOGLE_PROTOBUF_NO_RTTI',
      'GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER',
    ],
    # TODO(jschuh): http://crbug.com/167187 size_t -> int.
    'msvs_disabled_warnings': [ 4267 ],
  },
}
