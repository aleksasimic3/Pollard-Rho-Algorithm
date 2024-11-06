#include "pollardRho.h"

namespace {
//g(x) = (x^2 + b) % n
uint64_t polynomial(uint64_t x, uint64_t b, uint64_t n) {

	unsigned __int128 _x = x % n;
	unsigned __int128 _b = b;
	unsigned __int128 _n = n;

	unsigned __int128 res = (_x*_x + _b) % _n;

	return (uint64_t)res;
}
}

uint64_t findDivisor(uint64_t n, bool skipPrimeCheck) {

	if(n <= 1) return 1;
	if(n % 2 == 0) return 2;

	const std::vector<unsigned> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
	for(auto prime : primes) if(n % prime == 0) return prime;

	if(skipPrimeCheck == false) {
		uint64_t possibleDivisor = 0;
		if(isPrime(n, &possibleDivisor)) return 1;
		if(possibleDivisor != 0) return possibleDivisor;
	}
	//after this point it is safe to treat n as composite

	uint64_t x = 2;
	uint64_t y = x;
	uint64_t d = 1;
	uint64_t b = 1;

	while(d == 1) {
		x = polynomial(x, b, n); //x = g(x)
		y = polynomial(polynomial(y, b, n), b, n); //y = g(g(y))
		d = std::gcd((x>y)?x-y:y-x, n);

		if(d == n) { //failure case, try a different polynomial (increment b)
			x = 2; //reset values
			y = x;
			d = 1;
			b++;
		}
	}

	return d;
}

int findDivisor(int n, bool skipPrimeCheck) {
	if(n < 0) n = -n;
	return findDivisor((uint64_t)n, skipPrimeCheck);
}