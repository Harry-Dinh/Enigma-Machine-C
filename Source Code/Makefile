cflag = -std=c++11
objects = Rotor.o

all:
	g++ $(cflag) -o enigma $(objects) main.cc

Rotor.o: Rotor.h Rotor.cc
	g++ $(cflag) -c Rotor.cc

clean:
	rm -f enigma *.o