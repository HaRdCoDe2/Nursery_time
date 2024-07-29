SRCS = $(wildcard src/*.cpp)

make linux:
	g++ $(SRCS) -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer  -o main

make window:
	g++  -I include/ -L lib/ $(SRCS)  -lmingw32 -lSDL2 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -o main.exe
