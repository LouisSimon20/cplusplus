CXX=g++
CXXFLAGS=-g
RM=rm -f

#L'executable principal permettant d'utiliser le traducteur
tradu : obj/main.o obj/wavtomorse.o obj/morsetowav.o obj/frtomorse.o obj/morsetofr.o
	$(CXX) $(CXXFLAGS) $^ -o $@

#Executable de tests
test : obj/maintest.o obj/test-trad.o obj/wavtomorse.o obj/morsetowav.o obj/frtomorse.o obj/morsetofr.o
	$(CXX) $(CXXFLAGS) $^ -o $@

#Creation des .o
./obj/%.o: ./src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

#Regles de nettoyage
cleanexe:
	$(RM) tradu test

cleanall:
	$(RM) tradu test obj/maintest.o obj/main.o obj/wavtomorse.o obj/morsetowav.o obj/frtomorse.o obj/morsetofr.o