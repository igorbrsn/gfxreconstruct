/*
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef BRIMSTONE_UTIL_FILE_OUTPUT_STREAM_H
#define BRIMSTONE_UTIL_FILE_OUTPUT_STREAM_H

#include <cstdio>
#include <string>

#include "util/defines.h"
#include "util/output_stream.h"
#include "util/platform.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)

class FileOutputStream : public OutputStream
{
  public:
    FileOutputStream(const std::string& filename, bool append = false);

    FileOutputStream(FILE* file, bool owned = false);

    virtual ~FileOutputStream();

    virtual bool IsValid() override { return (file_ != nullptr); }

    virtual size_t Write(const void* data, size_t len) override;

  private:
    FILE* file_;
    bool  own_file_;
};

BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_UTIL_FILE_OUTPUT_STREAM_H