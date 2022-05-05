// Copyright (C) 2022 The Falco Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Package libs provides a Go wrapper for the Libs public APIs.
package libs

const SCAP_SUCCESS int = 0
const SCAP_FAILURE int = 1
const SCAP_TIMEOUT int = -1
const SCAP_ILLEGAL_INPUT int = 3
const SCAP_NOTFOUND int = 4
const SCAP_INPUT_TOO_SMALL int = 5
const SCAP_EOF int = 6
const SCAP_UNEXPECTED_BLOCK int = 7
const SCAP_VERSION_MISMATCH int = 8
const SCAP_NOT_SUPPORTED int = 9

//
// Last error string size for scap_open_live()
//
const SCAP_LASTERR_SIZE int = 256
