boid: Boid.o Vecteur.o main.o BoidSimulator.o
	g++ -std=c++11 -o boid $^ -lsfml-graphics -lsfml-window -lsfml-system -lm


%.o: %.c
	g++ -std=c++11 -g -c $^


clean:
	rm -f *.o
