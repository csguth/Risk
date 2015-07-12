# additional include paths necessary to compile the C++ programs
AM_CXXFLAGS = -std=c++11 -I$(top_srcdir)/src @AM_CXXFLAGS@

###############################################################################
# THE PROGRAMS TO BUILD
###############################################################################

# the program to build (the names of the final binaries)
bin_PROGRAMS = $(top_builddir)/bin/risk
__top_builddir__bin_risk_SOURCES = main.cpp

# the additional libraries needed to link helloWorld
__top_builddir__bin_risk_LDADD =  $(top_builddir)/src/die/libriskdie.a $(AM_LDFLAGS)

###############################################################################