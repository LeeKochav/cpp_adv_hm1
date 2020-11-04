#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

HEADERS := $(wildcard *.h*)
STUDENT_OBJECTS= main.o Editor.o Document.o


ed2: main.o $(STUDENT_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o ed2

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o ed2