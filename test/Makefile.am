top=../
gtest_dir=${top}../gtest/gtest-1.6.0/

SUBDIRS=

AM_CXXFLAGS=-Wall -std=c++0x -I${top} -I${gtest_dir}/include/
TESTS = test

check_PROGRAMS = test
test_LDFLAGS=-L${gtest_dir}/lib/ -L${top}src   
test_LDADD= -lgtest -lpthread -lmetasim 
test_SOURCES = test_main.cpp \
	stub.cpp
