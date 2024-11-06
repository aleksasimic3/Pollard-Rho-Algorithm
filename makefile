CC = g++
INCLUDE = -Iinclude
CFLAGS = -Wall -O3
LIBS = -lmpfr -lgmp -lgmpxx

SOURCE_DIR = src/
INCLUDE_DIR = include/
BINARY_DIR = bin/
TEST_DIR = test/

divisors.exe: main.o pollardRho.o millerRabin.o pollardRhoMP.o millerRabinMP.o
	$(CC) -o $(BINARY_DIR)divisors.exe main.o pollardRho.o millerRabin.o pollardRhoMP.o millerRabinMP.o $(CFLAGS) $(LIBS) -static

test.exe: test.o pollardRho.o millerRabin.o
	$(CC) -o $(BINARY_DIR)test.exe test.o pollardRho.o millerRabin.o $(CFLAGS) $(LIBS) -static

main.o: $(SOURCE_DIR)main.cpp $(INCLUDE_DIR)pollardRho.h
	$(CC) -c -o main.o $(SOURCE_DIR)main.cpp $(CFLAGS) $(INCLUDE)

pollardRho.o: $(SOURCE_DIR)pollardRho.cpp $(INCLUDE_DIR)pollardRho.h
	$(CC) -c -o pollardRho.o $(SOURCE_DIR)pollardRho.cpp $(CFLAGS) $(INCLUDE)

pollardRhoMP.o: $(SOURCE_DIR)pollardRhoMP.cpp $(INCLUDE_DIR)pollardRhoMP.h
	$(CC) -c -o pollardRhoMP.o $(SOURCE_DIR)pollardRhoMP.cpp $(CFLAGS) $(INCLUDE)

millerRabin.o: $(SOURCE_DIR)millerRabin.cpp $(INCLUDE_DIR)millerRabin.h
	$(CC) -c -o millerRabin.o $(SOURCE_DIR)millerRabin.cpp $(CFLAGS) $(INCLUDE)

millerRabinMP.o: $(SOURCE_DIR)millerRabinMP.cpp $(INCLUDE_DIR)millerRabinMP.h
	$(CC) -c -o millerRabinMP.o $(SOURCE_DIR)millerRabinMP.cpp $(CFLAGS) $(INCLUDE)

test.o: $(TEST_DIR)test.cpp $(INCLUDE_DIR)pollardRho.h
	$(CC) -c -o test.o $(TEST_DIR)test.cpp $(CFLAGS) $(INCLUDE)


.PHONY: clean
clean:
	rm main.o
	rm pollardRho.o
	rm pollardRhoMP.o
	rm millerRabin.o
	rm millerRabinMP.o
	rm test.o