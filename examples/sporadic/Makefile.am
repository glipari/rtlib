top=../..
metasim_dir=${top}/../metasim/src
rtlib_dir=${top}/src

AM_CPPFLAGS = -I$(metasim_dir) -I$(rtlib_dir) -Wall -std=c++0x

AM_LDFLAGS = -L$(metasim_dir) -L$(rtlib_dir) -lmetasim -lrtlib

noinst_PROGRAMS = spsl sprunt1

spsl_SOURCES = spsl.cpp 
sprunt1_SOURCES = sprunt_example1.cpp 

CLEANFILES = debug.txt trace.trc trace.txt
