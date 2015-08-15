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
						storage_test.cpp \
						player_test.cpp \
						die_test.cpp \
						map_test.cpp \
						bonus_test.cpp \
						domination_test.cpp \
                        run_tests.cpp

# the additional libraries needed to link helloWorld
run_tests_LDADD =  \
	$(top_builddir)/src/utils/libriskutils.a \
	$(top_builddir)/src/die/libriskdie.a \
	$(top_builddir)/src/player/libriskplayer.a \
	$(top_builddir)/src/map/libriskmap.a \
	$(top_builddir)/src/bonus/libriskbonus.a \
	$(top_builddir)/src/domination/libriskdomination.a \
	$(AM_LDFLAGS)


###############################################################################
