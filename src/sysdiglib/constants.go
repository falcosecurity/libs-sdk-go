package sysdiglib
import "C"
const SCAP_SUCCESS C.int = 0
const SCAP_FAILURE C.int = 1
const SCAP_TIMEOUT C.int = -1
const SCAP_ILLEGAL_INPUT C.int = 3
const SCAP_NOTFOUND C.int = 4
const SCAP_INPUT_TOO_SMALL C.int = 5
const SCAP_EOF C.int = 6
const SCAP_UNEXPECTED_BLOCK C.int = 7
const SCAP_VERSION_MISMATCH C.int = 8
const SCAP_NOT_SUPPORTED C.int = 9

//
// Last error string size for scap_open_live()
//
const SCAP_LASTERR_SIZE C.int = 256
