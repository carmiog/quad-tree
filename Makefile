CXX=g++-5
CFLAGS=-std=c++11 -fpic -c
LDFLAGS=
OBJS=*.o
.cpp.o:
	$(CXX) $(CFLAGS) $<

all: $(OBJS)
	$(CXX) -dynamiclib -o libquadtree.dylib $(OBJS)
	
clean:
	rm -f *.o
