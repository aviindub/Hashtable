BUILD = ../build
CPP = g++
CPPFLAGS = -Wall -Wextra

main: hash_tester.cpp Hashtable.o
	$(CPP) $(CPPFLAGS) hash_tester.cpp Hashtable.o

Hashtable.o: Hashtable.h Hashtable.cpp Entry.o
	$(CPP) $(CPPFLAGS) -c Hashtable.cpp

Entry.o: Entry.h Entry.cpp
	$(CPP) $(CPPFLAGS) -c Entry.cpp

clean:
	rm -f *.o
	rm -f *~
	rm -f $(BUILD)
