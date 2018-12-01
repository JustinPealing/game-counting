objects = src/main.o src/GameEngine.o src/FpsCounter.o
CPPFLAGS += -Iinclude
LDFLAGS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

counting : ${objects}
	g++ ${objects} -o counting $(LDFLAGS)

clean:
	rm counting $(objects)