# additional include pathes necessary to compile the C++ library
AM_CXXFLAGS = -std=c++11 -I$(top_srcdir)/src @AM_CXXFLAGS@

###############################################################################
# THE LIBRARIES TO BUILD
###############################################################################

# the library names to build (note we are building static libs only)
lib_LIBRARIES = libriskdomination.a

# where to install the headers on the system
libriskdomination_adir = $(includedir)/libriskdomination



# the list of header files that belong to the library (to be installed later)
libriskdomination_a_HEADERS =	\
						conqueror_player.h \
						conquerable_territory.h

# the sources to add to the library and to add to the source distribution
libriskdomination_a_SOURCES =	\
						$(libriskdomination_a_HEADERS) \
						conqueror_player.cpp \
						conquerable_territory.cpp
						
###############################################################################