#
# Makefile för smart_pointer och GNU GCC.
#
CCC      = g++
CCFLAGS += -std=c++98 -pedantic -Wall -Wextra

smart_pointer-test: smart_pointer-test.o smart_pointer.o  Makefile
	$(CCC) $(CCFLAGS) -o smart_pointer-test smart_pointer-test.o smart_pointer.o

smart_pointer-test.o: smart_pointer.h smart_pointer-test.cc
	$(CCC) $(CCFLAGS) -c smart_pointer-test.cc

smart_pointer.o: smart_pointer.cc
	$(CCC) $(CCFLAGS) -c smart_pointer.cc

clean:
	@ \rm -f *.o

zap: clean
	@ \rm -rf  smart_pointer-test *~ 
