# additional include pathes necessary to compile the C++ library
AM_CXXFLAGS = -std=c++11 -I$(top_srcdir)/src @AM_CXXFLAGS@
AM_CPPFLAGS = -I$(top_srcdir)/include

###############################################################################
# THE LIBRARIES TO BUILD
###############################################################################

# the library names to build (note we are building static libs only)
lib_LIBRARIES = libriskbonus.a

# where to install the headers on the system
libriskbonus_adir = $(includedir)/libriskbonus

# the list of header files that belong to the library (to be installed later)
						bonus.h \
						continent_bonus.h \
						single_appliance_bonus.h \
						full_continent_bonus_factory.h \
						territory_bonus.h
						
# the sources to add to the library and to add to the source distribution
libriskbonus_a_SOURCES =	\
						$(libriskbonus_a_HEADERS) \
						continent_bonus.cpp \
						single_appliance_bonus.cpp \
						full_continent_bonus_factory.cpp \
						territory_bonus.cpp 
						
libriskbonus_a_LIBADD =  \
	$(top_builddir)/src/map/libriskmap.a \
	$(AM_LDFLAGS)

###############################################################################
