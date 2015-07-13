# additional include pathes necessary to compile the C++ library
AM_CXXFLAGS = -std=c++11 -I$(top_srcdir)/src @AM_CXXFLAGS@

###############################################################################
# THE LIBRARIES TO BUILD
###############################################################################

# the library names to build (note we are building static libs only)
lib_LIBRARIES = libriskdie.a

# where to install the headers on the system
libriskdie_adir = $(includedir)/libriskdie

# the list of header files that belong to the library (to be installed later)
libriskdie_a_HEADERS =	\
						die_random_engine.h \
						die_face.h \
						die.h \
						land_attack_die_face.h \
						land_defense_die_face.h \
						simple_die.h \
						land_attack_attack_die.h \
						land_attack_defense_die.h \
						land_attack_die_fight.h

# the sources to add to the library and to add to the source distribution
libriskdie_a_SOURCES =	\
						$(libriskdie_a_HEADERS) \
						die_random_engine.cpp \
						die_face.cpp \
						land_attack_die_face.cpp \
						land_defense_die_face.cpp \
						land_attack_attack_die.cpp \
						land_attack_defense_die.cpp \
						land_attack_die_fight.cpp
						
###############################################################################