# additional include pathes necessary to compile the C++ library
AM_CXXFLAGS = -std=c++11 -I$(top_srcdir)/src @AM_CXXFLAGS@
AM_CPPFLAGS = -I$(top_srcdir)/include

###############################################################################
# THE LIBRARIES TO BUILD
###############################################################################

# the library names to build (note we are building static libs only)
lib_LIBRARIES = libriskdomination.a

# where to install the headers on the system
libriskdomination_adir = $(includedir)/libriskdomination

# the list of header files that belong to the library (to be installed later)
						conquerable_map.h \
						empty_territory_state.h \
						owned_territory_state.h \
						territory_state.h
						
# the sources to add to the library and to add to the source distribution
libriskdomination_a_SOURCES =	\
						$(libriskdomination_a_HEADERS) \
						conquerable_map.cpp \
						empty_territory_state.cpp \
						owned_territory_state.cpp
						
libriskdomination_a_LIBADD =  \
	$(top_builddir)/src/map/libriskmap.a \
	$(AM_LDFLAGS)

###############################################################################
