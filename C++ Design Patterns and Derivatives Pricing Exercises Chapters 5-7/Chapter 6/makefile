# all:
# g++ -std=c++11 Antithetic.cpp Arrays.cpp ConvergenceTable.cpp MCStatistics.cpp Normals.cpp Parameters.cpp ParkMiller.cpp PayOff3.cpp PayOffBridge.cpp Random2.cpp SimpleMC8.cpp Vanilla3.cpp RandomMain3.cpp -o a.out


CC=g++ -std=c++11
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Antithetic.cpp Arrays.cpp ConvergenceTable.cpp MCStatistics.cpp Normals.cpp Parameters.cpp ParkMiller.cpp PayOff3.cpp PayOffBridge.cpp Random2.cpp SimpleMC8.cpp Vanilla3.cpp RandomMain3.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=a.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

