# all:
# 	g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2

all:
	g++ -I src/include -L src/lib main.cpp Screen.cpp Particle.cpp Swarm.cpp -o main -lmingw32 -lSDL2main -lSDL2
