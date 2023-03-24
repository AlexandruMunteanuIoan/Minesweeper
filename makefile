CXX=g++
CXXFLAGS=-Wall -Werror -std=c++11
SRCDIR=./
SRC=$(shell find $(SRCDIR) -name '*.cpp')
OBJ=$(SRC:%.cpp=%.o)
EXEC=main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

