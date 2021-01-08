CXX=g++
CXXFLAGS=-g
RM=rm -f

liste : intlist.o main.o testintlist.o
	$(CXX) $(CXXFLAGS) $^ -o $@

intlist.o : intlist.cpp intlist.h
main.o : main.cpp TestIntList.h intlist.h
testintlist.o : TestIntList.cpp TestIntList.h intlist.h intlist.cpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<
clean:
	$(RM) liste intlist.o testintlist.o main.o 