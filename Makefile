CXX = g++
CXXFLAGS = -pedantic -std=c++11
EXECUTABLE = pacman
LDFLAGS = -lncursesw
OBJECTS = Character.o main.o Screen.o GameObject.o PlayableMap.o Pill.o Ghosts.o RedGhost.o

compile: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJECTS) $(LDFLAGS)

main.o: main.cpp Screen.h Character.h 
	$(CXX) $(FLAGS) -c $<

Screen.o: Screen.cpp Screen.h Character.h PlayableMap.h
	$(CXX) $(FLAGS) -c $<

Character.o: Character.cpp Character.h GameObject.h GameObject.cpp
	$(CXX) $(FLAGS) -c $<

GameObject.o: GameObject.cpp GameObject.h
	$(CXX) $(FLAGS) -c $<

PlayableMap.o: PlayableMap.cpp PlayableMap.h
	$(CXX) $(FLAGS) -c $<

Pill.o: Pill.cpp Pill.h GameObject.h GameObject.cpp
	$(CXX) $(FLAGS) -c $<

Ghosts.o: Ghosts.cpp Ghosts.h GameObject.h 
	$(CXX) $(FLAGS) -c $<

RedGhost.o: RedGhost.cpp RedGhost.h Ghosts.h
	$(CXX) $(FLAGS) -c $<

.PHONY: run
run:
	./$(EXECUTABLE)
