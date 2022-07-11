# Copyright (c) 2016 The WebRTC project authors. All Rights Reserved.
#
# Use of this source code is governed by a BSD-style license
# that can be found in the LICENSE file in the root of the source
# tree. An additional intellectual property rights grant can be found
# in the file PATENTS.  All contributing project authors may
# be found in the AUTHORS file in the root of the source tree.


def _CommonChecks(input_api, output_api):
  results = []

  # Validate the format of the mb_config.pyl file.
  mb_script = input_api.os_path.join(input_api.PresubmitLocalPath(), '..',
                                     '..', 'tools', 'mb', 'mb.py')
  mb_config_path = input_api.os_path.join(input_api.PresubmitLocalPath(),
                                          'mb_config.pyl')
  cmd = [input_api.python_executable, mb_script, 'validate', '--config-file',
         mb_config_path]
  kwargs = {'cwd': input_api.PresubmitLocalPath()}
  results.extend(input_api.RunTests([
      input_api.Command(name='mb_validate',
                        cmd=cmd, kwargs=kwargs,
                        message=output_api.PresubmitError)]))

  return results


def CheckChangeOnUpload(input_api, output_api):
  return _CommonChecks(input_api, output_api)


def CheckChangeOnCommit(input_api, output_api):
  return _CommonChecks(input_api, output_api)
