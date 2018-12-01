counting : main.o GameEngine.o FpsCounter.o
	g++ main.o GameEngine.o FpsCounter.o \
		-o counting \
		-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o : src/main.cpp
	g++ -Iinclude -c src/main.cpp -o main.o

GameEngine.o : src/GameEngine.cpp
	g++ -Iinclude -c src/GameEngine.cpp -o GameEngine.o

FpsCounter.o : src/FpsCounter.cpp
	g++ -Iinclude -c src/FpsCounter.cpp -o FpsCounter.o
