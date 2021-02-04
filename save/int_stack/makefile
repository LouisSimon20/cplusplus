CXX=g++
CXXFLAGS=-g
RM=rm -f


int : IntStack.o test_intstack.o main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

IntStack.o : IntStack.cpp IntStack.h
test_intstack.o : test_intstack.cpp test_intstack.h IntStack.h
main.o : main.cpp test_intstack.h IntStack.h
foo.o : foo.cpp foo.h IntStack.h

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<
clean:
	$(RM) IntStack.o main.o test_intstack.o foo.o int



