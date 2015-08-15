# additional include pathes necessary to compile the C++ library
AM_CXXFLAGS = -std=c++11 -I$(top_srcdir)/src @AM_CXXFLAGS@

###############################################################################
# THE LIBRARIES TO BUILD
###############################################################################

# the library names to build (note we are building static libs only)
lib_LIBRARIES = libriskutils.a

# where to install the headers on the system
libriskutils_adir = $(includedir)/libriskutils

# the list of header files that belong to the library (to be installed later)
				 		storage.h

# the sources to add to the library and to add to the source distribution
libriskutils_a_SOURCES =	\
						$(libriskutils_a_HEADERS)
						
###############################################################################
