#include <iostream>
#include <cstdint>
#include <chrono>
#include <cstdlib>
#include <random>
#include <climits>

#include "pollardRho.h"

#define DEFAULT_LIMIT 10000u //DEFAULT_ITERATIONS

bool test_randomUint64(int iterations=DEFAULT_LIMIT);
bool test_randomMpz_class(int iterations=DEFAULT_LIMIT);

int main(int argc, char* argv[]) {

	//random test for uint64_t
	uint64_t limit = argc > 1 ? std::strtoull(argv[1], nullptr, 10) : DEFAULT_LIMIT;
	std::random_device rd;
	std::mt19937_64 e2(rd());
	std::uniform_int_distribution<uint64_t> dist(0, ULLONG_MAX);
	std::cout << "\nTesting " << limit << " random uint64_t numbers: ";
	auto startTime = std::chrono::high_resolution_clock::now();
	for(uint64_t i = 1; i <= limit; i++) {
		uint64_t n = dist(e2);
		uint64_t k = findDivisor(n);
		std::cout << n << " = " << k << " * " << n/k << '\n';
		if(n % k != 0) {
			std::cout << "ERROR! " << k << " does not divide " << n << '\n';
			return -1;
		}
	}
	auto endTime = std::chrono::high_resolution_clock::now();
	auto timeElapsed = endTime - startTime;
	std::cout << "OK (" << (timeElapsed / std::chrono::milliseconds(1)) << "ms)\n";

	//random test for mpz_class

	return 0;
}

bool test_randomUint64(int iterations) {

	//set limit

	//initialize random number engine

	//start timer

	//loop trough numbers and check for errors

	//end timer

	return true;
}