boid: Boid.o Vecteur.o main.o BoidSimulator.o
	g++ -std=c++11 -g -o boid $^ -lsfml-graphics -lsfml-window -lsfml-system -lm

%.o: %.cpp
	g++ -g -c $^

clean:
	rm -f *.o
