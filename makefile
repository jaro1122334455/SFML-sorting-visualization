hellomake: main.cpp line.cpp algorithms.cpp

	g++ -c main.cpp line.cpp algorithms.cpp
	g++ main.o line.o algorithms.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app
	