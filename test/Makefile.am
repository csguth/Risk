# additional include paths necessary to compile the C++ programs
AM_CXXFLAGS = -std=c++11 -I$(top_srcdir)/test @AM_CXXFLAGS@
###############################################################################
# THE PROGRAMS TO BUILD
###############################################################################

# the program to build (the names of the final binaries)
bin_PROGRAMS = die_test

AM_CPPFLAGS = -I$(top_srcdir)/include

# list of sources for the 'helloWorld' binary
die_test_SOURCES =    \
                        die_test.cpp

# the additional libraries needed to link helloWorld
die_test_LDADD =  $(top_builddir)/src/die/libriskdie.a $(AM_LDFLAGS)

###############################################################################