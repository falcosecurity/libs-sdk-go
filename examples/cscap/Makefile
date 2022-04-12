
FALCOLIBPREFIX = /usr/lib/x86_64-linux-gnu/falcosecurity
FALCOINCLUDEPREFIX = /usr/include/falcosecurity
CXX = gcc
CFLAGS = -D_GNU_SOURCE -DHAS_CAPTURE -Wall -DNDEBUG \
		-I$(FALCOINCLUDEPREFIX)/ \
		-I$(FALCOINCLUDEPREFIX)/userspace/libsinsp \
		-I$(FALCOINCLUDEPREFIX)/userspace/libscap \
		-I/src/c++/
LDFLAGS = -L/usr/lib/x86_64-linux-gnu/falcosecurity/ -L/src/c++/ -lfalcolibs \
		$(FALCOLIBPREFIX)/libsinsp.a $(FALCOLIBPREFIX)/libscap.a $(FALCOLIBPREFIX)/libjq.a $(FALCOLIBPREFIX)/libonig.a \
		$(FALCOLIBPREFIX)/libb64.a $(FALCOLIBPREFIX)/libcurl.a $(FALCOLIBPREFIX)/libtbb.a $(FALCOLIBPREFIX)/libgrpc++.a \
		$(FALCOLIBPREFIX)/libgrpc++_alts.a $(FALCOLIBPREFIX)/libgrpc++_reflection.a  $(FALCOLIBPREFIX)/libgrpc++_error_details.a \
		$(FALCOLIBPREFIX)/libgrpc++_unsecure.a  $(FALCOLIBPREFIX)/libgrpc_plugin_support.a $(FALCOLIBPREFIX)/libgrpcpp_channelz.a \
		$(FALCOLIBPREFIX)/libgrpc.a $(FALCOLIBPREFIX)/libgpr.a -lcares -lprotobuf  \
		$(FALCOLIBPREFIX)/libsinsp.a $(FALCOLIBPREFIX)/libscap.a $(FALCOLIBPREFIX)/libjq.a $(FALCOLIBPREFIX)/libonig.a \
		$(FALCOLIBPREFIX)/libabsl_synchronization.a $(FALCOLIBPREFIX)/libabsl_graphcycles_internal.a  $(FALCOLIBPREFIX)/libabsl_status.a \
		$(FALCOLIBPREFIX)/libabsl_statusor.a $(FALCOLIBPREFIX)/libabsl_strings.a $(FALCOLIBPREFIX)/libabsl_strings_internal.a \
		$(FALCOLIBPREFIX)/libabsl_cord.a $(FALCOLIBPREFIX)/libabsl_cordz_functions.a $(FALCOLIBPREFIX)/libabsl_cord_internal.a \
		$(FALCOLIBPREFIX)/libabsl_cordz_info.a $(FALCOLIBPREFIX)/libabsl_cordz_handle.a $(FALCOLIBPREFIX)/libabsl_hash.a \
		$(FALCOLIBPREFIX)/libabsl_city.a $(FALCOLIBPREFIX)/libabsl_low_level_hash.a $(FALCOLIBPREFIX)/libabsl_raw_hash_set.a \
		$(FALCOLIBPREFIX)/libabsl_hashtablez_sampler.a  $(FALCOLIBPREFIX)/libabsl_random_internal_pool_urbg.a \
		$(FALCOLIBPREFIX)/libabsl_random_internal_randen.a $(FALCOLIBPREFIX)/libabsl_random_internal_randen_hwaes.a \
		$(FALCOLIBPREFIX)/libabsl_random_internal_randen_hwaes_impl.a $(FALCOLIBPREFIX)/libabsl_random_internal_platform.a \
		$(FALCOLIBPREFIX)/libabsl_random_internal_randen_slow.a $(FALCOLIBPREFIX)/libabsl_random_internal_seed_material.a \
		$(FALCOLIBPREFIX)/libabsl_random_seed_gen_exception.a $(FALCOLIBPREFIX)/libabsl_exponential_biased.a \
		$(FALCOLIBPREFIX)/libabsl_bad_variant_access.a $(FALCOLIBPREFIX)/libabsl_str_format_internal.a  \
		$(FALCOLIBPREFIX)/libabsl_raw_logging_internal.a $(FALCOLIBPREFIX)/libabsl_malloc_internal.a $(FALCOLIBPREFIX)/libabsl_base.a \
		$(FALCOLIBPREFIX)/libabsl_spinlock_wait.a $(FALCOLIBPREFIX)/libabsl_throw_delegate.a $(FALCOLIBPREFIX)/libabsl_log_severity.a \
		$(FALCOLIBPREFIX)/libabsl_bad_optional_access.a $(FALCOLIBPREFIX)/libabsl_time.a $(FALCOLIBPREFIX)/libabsl_time_zone.a \
		$(FALCOLIBPREFIX)/libabsl_int128.a $(FALCOLIBPREFIX)/libabsl_stacktrace.a $(FALCOLIBPREFIX)/libabsl_symbolize.a \
		$(FALCOLIBPREFIX)/libabsl_debugging_internal.a $(FALCOLIBPREFIX)/libabsl_demangle_internal.a \
		-lelf -lstdc++ -lz -lrt -lanl -lssl -lcrypto -lpthread -lm -ldl -lupb -laddress_sorting -lre2

cscap: main.o
	$(CXX) $^ -o $@ $(LDFLAGS)

main.o: main.cpp
	$(CXX) $(CFLAGS) -o $@ -c $^

.PHONY: clean
clean:
	rm -f *.o *.so *.a cscap
