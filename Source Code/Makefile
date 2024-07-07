# Enigma Machine (C++ Edition) Makefile
# Built by Harry Dinh
# ======================================

# Standard C++ version flag and a variable containing all of the variables to compile into objects
cflag = -std=c++11
objects = Rotor.o

# Compile and run the program without any debugging tools attached
run: compile
	./enigma

# Compile and run the program with the Valgrind leak-checking tool attached
vrun: compile
	valgrind --leak-check=full ./enigma

# Compile the all of the classes into object files to create the `enigma` executable
compile: Rotor.o
	g++ $(cflag) -o enigma $(objects) main.cc

# Compile the Rotor class into an object file
Rotor.o: Rotor.h Rotor.cc
	g++ $(cflag) -c Rotor.cc

# Clean up the workspace by removing all object files and the `enigma` executable
clean:
	rm -f enigma *.o