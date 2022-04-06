
SDLOCALLIBPREFIX = /usr/lib/x86_64-linux-gnu/falcosecurity
CXX = gcc
CFLAGS = -D_GNU_SOURCE -DHAS_CAPTURE -Wall -DNDEBUG
LDFLAGS = -L/usr/lib/x86_64-linux-gnu/falcosecurity/ -L/src/c++/ -lfalcolibs $(SDLOCALLIBPREFIX)/libsinsp.a $(SDLOCALLIBPREFIX)/libscap.a $(SDLOCALLIBPREFIX)/libjq.a $(SDLOCALLIBPREFIX)/libonig.a \
      $(SDLOCALLIBPREFIX)/libb64.a $(SDLOCALLIBPREFIX)/libcurl.a $(SDLOCALLIBPREFIX)/libtbb.a $(SDLOCALLIBPREFIX)/libgrpc++.a \
	  $(SDLOCALLIBPREFIX)/libgrpc++_alts.a $(SDLOCALLIBPREFIX)/libgrpc++_reflection.a  $(SDLOCALLIBPREFIX)/libgrpc++_error_details.a \
	  $(SDLOCALLIBPREFIX)/libgrpc++_unsecure.a  $(SDLOCALLIBPREFIX)/libgrpc_plugin_support.a $(SDLOCALLIBPREFIX)/libgrpcpp_channelz.a \
	  $(SDLOCALLIBPREFIX)/libgrpc.a $(SDLOCALLIBPREFIX)/libgpr.a -lcares -lprotobuf  \
          $(SDLOCALLIBPREFIX)/libsinsp.a $(SDLOCALLIBPREFIX)/libscap.a $(SDLOCALLIBPREFIX)/libjq.a $(SDLOCALLIBPREFIX)/libonig.a \
           $(SDLOCALLIBPREFIX)/libabsl_synchronization.a $(SDLOCALLIBPREFIX)/libabsl_graphcycles_internal.a  $(SDLOCALLIBPREFIX)/libabsl_status.a $(SDLOCALLIBPREFIX)/libabsl_statusor.a $(SDLOCALLIBPREFIX)/libabsl_strings.a $(SDLOCALLIBPREFIX)/libabsl_strings_internal.a $(SDLOCALLIBPREFIX)/libabsl_cord.a $(SDLOCALLIBPREFIX)/libabsl_cordz_functions.a $(SDLOCALLIBPREFIX)/libabsl_cord_internal.a $(SDLOCALLIBPREFIX)/libabsl_cordz_info.a $(SDLOCALLIBPREFIX)/libabsl_cordz_handle.a $(SDLOCALLIBPREFIX)/libabsl_hash.a $(SDLOCALLIBPREFIX)/libabsl_city.a $(SDLOCALLIBPREFIX)/libabsl_low_level_hash.a $(SDLOCALLIBPREFIX)/libabsl_raw_hash_set.a $(SDLOCALLIBPREFIX)/libabsl_hashtablez_sampler.a  $(SDLOCALLIBPREFIX)/libabsl_random_internal_pool_urbg.a $(SDLOCALLIBPREFIX)/libabsl_random_internal_randen.a $(SDLOCALLIBPREFIX)/libabsl_random_internal_randen_hwaes.a $(SDLOCALLIBPREFIX)/libabsl_random_internal_randen_hwaes_impl.a $(SDLOCALLIBPREFIX)/libabsl_random_internal_platform.a $(SDLOCALLIBPREFIX)/libabsl_random_internal_randen_slow.a $(SDLOCALLIBPREFIX)/libabsl_random_internal_seed_material.a $(SDLOCALLIBPREFIX)/libabsl_random_seed_gen_exception.a $(SDLOCALLIBPREFIX)/libabsl_exponential_biased.a $(SDLOCALLIBPREFIX)/libabsl_bad_variant_access.a $(SDLOCALLIBPREFIX)/libabsl_str_format_internal.a  $(SDLOCALLIBPREFIX)/libabsl_raw_logging_internal.a $(SDLOCALLIBPREFIX)/libabsl_malloc_internal.a $(SDLOCALLIBPREFIX)/libabsl_base.a $(SDLOCALLIBPREFIX)/libabsl_spinlock_wait.a $(SDLOCALLIBPREFIX)/libabsl_throw_delegate.a $(SDLOCALLIBPREFIX)/libabsl_log_severity.a $(SDLOCALLIBPREFIX)/libabsl_bad_optional_access.a $(SDLOCALLIBPREFIX)/libabsl_time.a $(SDLOCALLIBPREFIX)/libabsl_time_zone.a $(SDLOCALLIBPREFIX)/libabsl_int128.a $(SDLOCALLIBPREFIX)/libabsl_stacktrace.a $(SDLOCALLIBPREFIX)/libabsl_symbolize.a $(SDLOCALLIBPREFIX)/libabsl_debugging_internal.a $(SDLOCALLIBPREFIX)/libabsl_demangle_internal.a \
	  -lelf -lstdc++ -lz -lrt -lanl -lssl -lcrypto -lpthread -lm -ldl -lupb -laddress_sorting -lre2 
  
cscap: main.o
	$(CXX) $^ -o $@ $(LDFLAGS)

main.o: main.cpp
	$(CXX) $(CFLAGS) -o $@ -c $^ -I/usr/include/falcosecurity/ -I/usr/include/falcosecurity/userspace/libsinsp -I/usr/include/falcosecurity/userspace/libscap -I/src/c++/

.PHONY: clean
clean:
	rm -f *.o *.so *.a cscap
