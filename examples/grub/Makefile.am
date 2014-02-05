top=../..

metasim_dir=${top}/../metasim/src
rtlib_dir=${top}/src

AM_CPPFLAGS = -I$(metasim_dir) -I${rtlib_dir} -Wall -std=c++0x 

AM_LDFLAGS = -L${metasim_dir} -L${rtlib_dir} -lmetasim -lrtlib -lboost_program_options

noinst_PROGRAMS = grub gruball

grub_SOURCES = grub.cpp

gruball_SOURCES = gruball.cpp

CLEANFILES = trace.trc
