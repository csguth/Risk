dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(Risk, 1.0)


AC_CANONICAL_SYSTEM

# check for C++ preprocessor and compiler and the library compiler
AC_PROG_CXXCPP
AC_PROG_CXX
AC_PROG_RANLIB

AM_INIT_AUTOMAKE()

# use the C++ compiler for the following checks
AC_LANG([C++])

# distribute additional compiler and linker flags
# --> set these variables instead of CXXFLAGS or LDFLAGS
AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_LDFLAGS])

AC_CONFIG_FILES(Makefile src/bonus/Makefile src/map/Makefile src/die/Makefile src/player/Makefile src/Makefile test/Makefile)

# generate the final Makefile etc.
AC_OUTPUT


