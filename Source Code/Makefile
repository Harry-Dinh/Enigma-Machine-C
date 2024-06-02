cflag = -std=c++11
objects = Rotor.o

run: compile
	./enigma

vrun: compile
	valgrind --leak-check=full ./enigma

compile: Rotor.o
	g++ $(cflag) -o enigma $(objects) main.cc

Rotor.o: Rotor.h Rotor.cc
	g++ $(cflag) -c Rotor.cc

clean:
	rm -f enigma *.o