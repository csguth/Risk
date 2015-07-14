# additional include paths necessary to compile the C++ programs
AM_CXXFLAGS = -std=c++11 -I$(top_srcdir)/test @AM_CXXFLAGS@
###############################################################################
# THE PROGRAMS TO BUILD
###############################################################################

# the program to build (the names of the final binaries)
bin_PROGRAMS = run_tests

AM_CPPFLAGS = -I$(top_srcdir)/include

# list of sources for the 'helloWorld' binary
run_tests_SOURCES =    \
						map_test.cpp \
						player_test.cpp \
						die_test.cpp \
                        run_tests.cpp

# the additional libraries needed to link helloWorld
run_tests_LDADD =  \
	$(top_builddir)/src/die/libriskdie.a \
	$(top_builddir)/src/player/libriskplayer.a \
	$(top_builddir)/src/map/libriskmap.a \
	$(AM_LDFLAGS)


###############################################################################