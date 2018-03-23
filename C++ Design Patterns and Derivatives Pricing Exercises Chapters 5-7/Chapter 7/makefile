# all:
# g++ -std=c++11 Antithetic.cpp Arrays.cpp ConvergenceTable.cpp ExoticBSEngine.cpp ExoticEngine.cpp MCStatistics.cpp Normals.cpp Parameters.cpp ParkMiller.cpp PathDependent.cpp PathDependentAsian.cpp PayOff3.cpp PayOffBridge.cpp Random2.cpp EquityFXMain.cpp -o a.out


CC=g++ -std=c++11
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Antithetic.cpp Arrays.cpp ConvergenceTable.cpp ExoticBSEngine.cpp ExoticEngine.cpp MCStatistics.cpp Normals.cpp Parameters.cpp ParkMiller.cpp PathDependent.cpp PathDependentAsian.cpp PayOff3.cpp PayOffBridge.cpp Random2.cpp EquityFXMain.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=a.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

