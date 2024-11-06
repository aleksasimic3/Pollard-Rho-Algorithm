#include <iostream>
#include <cstdlib> 
#include <chrono>
#include <cstdint>
#include <string>

#include <gmp.h>
#include <gmpxx.h>

#include "pollardRho.h"
#include "pollardRhoMP.h"

int main(int argc, char* argv[]) {

	if(argc < 2) return 0;

	auto startTime = std::chrono::high_resolution_clock::now();

	mpz_class n = mpz_class(std::string(argv[1]));
	mpz_class k = findDivisor(n);

	auto endTime = std::chrono::high_resolution_clock::now();
	auto timeElapsed = endTime - startTime;

	std::cout << '\n' << n.get_str() << " = " << k.get_str() << " * " << n/k << '\n';
	std::cout << "\nCalculated in " << (timeElapsed / std::chrono::milliseconds(1)) << "ms\n";

	return 0;
}