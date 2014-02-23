top=../

metasim_dir=${top}../metasim/src

SUBDIRS=
EXTRA_DIST=

AM_CPPFLAGS = -I${top} -I${metasim_dir} -Wall -std=c++11 
AM_LDFLAGS = -L${metasim_dir} -lmetasim

lib_LTLIBRARIES = librtlib.la
librtlib_la_SOURCES = bwi.cpp capacitytimer.cpp cbserver.cpp cpu.cpp edfsched.cpp exeinstr.cpp \
	fcfsresmanager.cpp feedback.cpp feedbacktest.cpp fifosched.cpp \
	fpsched.cpp grubserver.cpp interrupt.cpp jtrace.cpp kernel.cpp kernevt.cpp load.cpp \
	mrtkernel.cpp piresman.cpp pollingserver.cpp reginstr.cpp regsched.cpp regtask.cpp \
	resmanager.cpp resource.cpp rmsched.cpp rrsched.cpp schedinstr.cpp \
	schedpoints.cpp schedrta.cpp scheduler.cpp server.cpp sparepot.cpp sporadicserver.cpp \
	supercbs.cpp task.cpp taskevt.cpp threinstr.cpp timer.cpp traceevent.cpp waitinstr.cpp instr.cpp

# feedbackarsim.cpp 
# rtload.cpp 
# grub.cpp 
