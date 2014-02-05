dnl Process this file with autoconf to produce a configure script

dnl AC_INIT(RTSIM, 2.0, g.lipari@sssup.it)
dnl AM_INIT_AUTOMAKE([src], 1.0)
AC_INIT([RTSIM], [2.0])
AC_CONFIG_SRCDIR([src/kernel.cpp])
AM_INIT_AUTOMAKE

AM_CONFIG_HEADER(config.h)
AC_CONFIG_MACRO_DIR([m4])
AC_PROG_CXX
AC_LANG(C++)
AC_PROG_LIBTOOL

AC_CHECK_PROGS(RANLIB, ranlib)

dnl should check for metasim presence ... 

AC_OUTPUT(Makefile src/Makefile test/Makefile 
		   examples/rm/Makefile 
		   examples/edf/Makefile 
		   examples/cbserver/Makefile 
		   examples/sporadic/Makefile 
		   examples/grub/Makefile
		   examples/prob/Makefile,
		   [date > stamp-h] )


dnl End the configure script.
