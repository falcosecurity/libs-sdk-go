package falcolibs

// #cgo LDFLAGS: -L${SRCDIR}/../c++/ -L/usr/lib/x86_64-linux-gnu/falcosecurity/ -lfalcolibs
// #cgo LDFLAGS: -lsinsp -lscap -ljq -lonig -lb64 -lcurl -ltbb -lgrpc++
// #cgo LDFLAGS: -lgrpc++_alts -lgrpc++_reflection  -lgrpc++_error_details
// #cgo LDFLAGS: -lgrpc -lgpr -lcares -lprotobuf -labsl_synchronization
// #cgo LDFLAGS: -labsl_graphcycles_internal  -labsl_status
// #cgo LDFLAGS: -labsl_statusor -labsl_strings
// #cgo LDFLAGS: -labsl_strings_internal -labsl_cord
// #cgo LDFLAGS: -labsl_cordz_functions -labsl_cord_internal -labsl_cordz_info
// #cgo LDFLAGS: -labsl_cordz_handle -labsl_hash -labsl_city -labsl_low_level_hash
// #cgo LDFLAGS: -labsl_raw_hash_set -labsl_hashtablez_sampler -labsl_random_internal_pool_urbg
// #cgo LDFLAGS: -labsl_random_internal_randen -labsl_random_internal_randen_hwaes
// #cgo LDFLAGS: -labsl_random_internal_randen_hwaes_impl -labsl_random_internal_platform
// #cgo LDFLAGS: -labsl_random_internal_randen_slow -labsl_random_internal_seed_material
// #cgo LDFLAGS: -labsl_random_seed_gen_exception -labsl_exponential_biased -labsl_bad_variant_access
// #cgo LDFLAGS: -labsl_str_format_internal  -labsl_raw_logging_internal
// #cgo LDFLAGS: -labsl_malloc_internal
// #cgo LDFLAGS: -labsl_base -labsl_spinlock_wait
// #cgo LDFLAGS: -labsl_throw_delegate -labsl_log_severity
// #cgo LDFLAGS: -labsl_bad_optional_access -labsl_time
// #cgo LDFLAGS: -labsl_time_zone -labsl_int128
// #cgo LDFLAGS: -labsl_stacktrace -labsl_symbolize
// #cgo LDFLAGS: -labsl_debugging_internal -labsl_demangle_internal
// #cgo LDFLAGS: -lstdc++ -lelf -lz -lrt -lanl -lssl -lcrypto -lpthread -lm -ldl -lupb -laddress_sorting -lre2
// #cgo CFLAGS: -D_GNU_SOURCE -DHAS_CAPTURE -fno-strict-aliasing -DNDEBUG
import "C"
