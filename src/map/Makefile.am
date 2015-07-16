# additional include pathes necessary to compile the C++ library
AM_CXXFLAGS = -std=c++11 -I$(top_srcdir)/src @AM_CXXFLAGS@

###############################################################################
# THE LIBRARIES TO BUILD
###############################################################################

# the library names to build (note we are building static libs only)
lib_LIBRARIES = libriskmap.a

# where to install the headers on the system
libriskmap_adir = $(includedir)/libriskmap

# the list of header files that belong to the library (to be installed later)
libriskmap_a_HEADERS =	\
						territory.h \
						continent.h \
						map.h \
						map_graph.h \
						map_parser.h

# the sources to add to the library and to add to the source distribution
libriskmap_a_SOURCES =	\
						$(libriskmap_a_HEADERS) \
						territory.cpp \
						continent.cpp \
						map_graph.cpp \
						map_parser.cpp \
						map.cpp

###############################################################################