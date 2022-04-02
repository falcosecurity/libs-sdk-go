package falcolibs

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
