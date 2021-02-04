CXX=g++
CXXFLAGS=-g -Wall
RM=rm -f

#graph : main.o graph.o
#	$(CXX) $(CXXFLAGS) $^ -o $@

#main.o : graph_main.cpp graph.h graph.cpp
#graph.o : graph.cpp graph.h

#%.o: %.cpp
#	$(CXX) $(CXXFLAGS) -o $@ -c $<

graph: graph_main.cpp graph.h graph.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) graph graph.o main.o 