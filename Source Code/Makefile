# Enigma Machine (C++ Edition) Makefile
# Built by Harry Dinh
# ======================================

# Standard C++ version flag and a variable containing all of the variables to compile into objects
cflag = -std=c++11 -g
objects = Rotor.o MainMenu.o EnigmaTest.o

# Compile and run the program without any debugging tools attached
run: compile
	./enigma

# Compile and run the program with LLDB for debugging (macOS only!)
debug: compile
	lldb ./enigma

# Compile the all of the classes into object files to create the `enigma` executable
compile: $(objects)
	g++ $(cflag) main.cc -o enigma $(objects)

# Compile the Rotor class into an object file
Rotor.o: Rotor.h Rotor.cc
	g++ $(cflag) -c Rotor.cc

# Compile the MainMenu class into an object file
MainMenu.o: MainMenu.h MainMenu.cc
	g++ $(cflag) -c MainMenu.cc

# Compile the EnigmaTest class into an object file (this will be removed when production is completed)
EnigmaTest.o: EnigmaTest.h EnigmaTest.cc
	g++ $(cflag) -c EnigmaTest.cc

# Clean up the workspace by removing all object files and the `enigma` executable
clean:
	rm -f enigma *.o