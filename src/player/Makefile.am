# additional include pathes necessary to compile the C++ library
AM_CXXFLAGS = -std=c++11 -I$(top_srcdir)/src @AM_CXXFLAGS@

###############################################################################
# THE LIBRARIES TO BUILD
###############################################################################

# the library names to build (note we are building static libs only)
lib_LIBRARIES = libriskplayer.a

# where to install the headers on the system
libriskplayer_adir = $(includedir)/libriskplayer

# the list of header files that belong to the library (to be installed later)
libriskplayer_a_HEADERS =	\
						player.h

# the sources to add to the library and to add to the source distribution
libriskplayer_a_SOURCES =	\
						$(libriskplayer_a_HEADERS) \
						player.cpp
						
###############################################################################