CXX = clang
G77 = g77
CPP = gcc -E
CXXFLAGS = -g -O2 -fPIC -Wno-deprecated -Wno-unused-command-line-argument
CFLAGS = -g -O2
CPPFLAGS =

INCFLAGS = -I.

LIBS = -lstdc++
LDFLAGS = -L. -lMyLib

all: read.exe

read.exe: read.h read.cc libMyLib.so
	$(CXX) $(CXXFLAGS) -o read.exe read.cc $(INCFLAGS) $(LDFLAGS) $(LIBS)

libMyLib.so: util.cc init.cc
	$(CXX) $(CXXFLAGS) -o util.o -c util.cc  $(INCFLAGS) $(LIBS)
	$(CXX) $(CXXFLAGS) -o init.o -c init.cc  $(INCFLAGS) $(LIBS)
	$(CXX) $(CXXFLAGS) -shared `ls *.o` -o libMyLib.so $(INCFLAGS) $(LIBS)

clean:
	rm -rf *.o libMyLib.so *.exe *.exe*
