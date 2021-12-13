# PROGRAM:    	complex_numbers
# PROGRAMMER: 	Kyin Edwards
# DATE WRITTEN: 3/3/2021

# Compiler variables.
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Rule to link object code files to create executable file.
assign6: main.o complex.o
	$(CXX) $(CXXFLAGS) -o assign6 $^

# Rules to compile source code files to object code.
main.o: main.cpp complex.h
complex.o: complex.cpp complex.h

# Phony target to remove object code and executable files.
clean:
	rm -f assign6 *.o
