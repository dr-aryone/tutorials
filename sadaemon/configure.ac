# Configures program name, version, and author contact information.
AC_INIT([sadaemon], [1.0], [david@davidstrauss.net])

# Configures Automake to use a non-GNU project layout with modern GNU extensions.
AM_INIT_AUTOMAKE([foreign 1.11 -Wall -Wno-portability silent-rules tar-pax no-dist-gzip dist-xz subdir-objects parallel-tests])

# We need a compiler and sed to build.
AC_PROG_CC
AC_PROG_SED

# Generates a configuration file for inclusion in the actual C code.
AC_CONFIG_HEADERS([config.h])

# The Makefiles to generate using the corresponding Makefile.am inputs.
AC_CONFIG_FILES([
 Makefile
 src/Makefile
])

# Link to systemd.
PKG_CHECK_MODULES(LIBSYSTEMD, [libsystemd >= 221], [], [AC_MSG_ERROR([*** libsystemd library not found])])

# Make it so.
AC_OUTPUT

