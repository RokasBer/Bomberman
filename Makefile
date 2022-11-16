CXX = g++
CXXFLAGS = -Wall -g -std=c++11 -IC:\SDL2-2.0.10\i686-w64-mingw32\include\SDL2
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
INC = -IC:\SDL2-2.0.10\i686-w64-mingw32\include\SDL2 -IC:\SDL2-2.0.10\SDL2_image-2.0.1\include
LIB = -LC:\SDL2-2.0.10\i686-w64-mingw32\lib -LC:\SDL2-2.0.10\SDL2_image-2.0.1\lib\x86

main: main.o bomb.o game.o map.o player.o TextureManager.o
	$(CXX) $(CXXFLAGS) -o BomberMan main.o bomb.o game.o map.o player.o TextureManager.o

main.o: game.h
	$(CXX) $(CXXFLAGS) -c  $(LINKER_FLAGS) main.cpp
bomb.o: bomb.h TextureManager.h player.h
	$(CXX) $(CXXFLAGS) $(LINKER_FLAGS) -c bomb.cpp
game.o: game.h TextureManager.h player.h map.h bomb.h
	$(CXX) $(CXXFLAGS) $(LINKER_FLAGS) -c game.cpp
map.o: map.h TextureManager.h
	$(CXX) $(CXXFLAGS) $(LINKER_FLAGS) -c map.cpp
player.o: player.h TextureManager.h
	$(CXX) $(CXXFLAGS) $(LINKER_FLAGS) -c player.cpp
TextureManager.o: TextureManager.h
	$(CXX) $(CXXFLAGS) $(LINKER_FLAGS) -c Texturemanager.cpp