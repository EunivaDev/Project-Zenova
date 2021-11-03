all:
	g++ -Iinclude -Iinclude/sdl -Iinclude/headers -Llib -o Project_Zenova src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image