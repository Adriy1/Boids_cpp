CXXFLAGS = -std=c++11 -g -fopenmp
LIBS =  -lsfml-graphics -lsfml-window -lsfml-system -lm

boid: Boid.o Vecteur.o main.o Boids.o BoidSimulator.o
	g++ $(CXXFLAGS)   -o boid $^ $(LIBS)

test: Boid.o Vecteur.o test.o Boids.o BoidSimulator.o
	g++  $(CXXFLAGS) -o testPerfOpti $^  $(LIBS)
	
%.o: %.cpp
	g++ $(CXXFLAGS) -c $^

clean:
	rm -f *.o

all: clean boid test
