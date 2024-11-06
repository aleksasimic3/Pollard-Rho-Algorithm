#include "pollardRhoMP.h"

namespace {
//g(x) = (x^2 + b) % n
mpz_class polynomial(mpz_class x, mpz_class b, mpz_class n) {
	mpz_class res = (x*x + b) % n;
	return res;
}

mpz_class gcd_mpz(mpz_class x, mpz_class y) {
	mpz_class t;
	while(y != 0) {
		t = y;
		y = x % y;
		x = t;
	}
	return x;
}
}

mpz_class findDivisor(mpz_class n, bool skipPrimeCheck) {

	if(n < mpz_class("18446744073709551616")) return mpz_class((unsigned)findDivisor((uint64_t)std::stoull(n.get_str(), nullptr, 10)));

	if(n <= 0) n *= -1;
	if(n <= mpz_class(1)) return mpz_class(1);
	if(n % 2 == 0) return mpz_class(2);

	const std::vector<unsigned> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
	for(auto prime : primes) {
		if(n % prime == 0) return mpz_class(prime);
	}

	if(!skipPrimeCheck) {
		if(isPrime(n)) return mpz_class(1);
	}

	//pollard rho test
	mpz_class x = mpz_class(2);
	mpz_class y = x;
	mpz_class d = mpz_class(1);
	mpz_class b = mpz_class(1);

	while(d == 1) {
		x = polynomial(x, b, n);
		y = polynomial(polynomial(y, b, n), b, n);
		d = gcd_mpz((x>y)?x-y:y-x, n);

		if(d == n) {
			std::cout << "d==n\n";
			x = 2;
			y = x;
			d = 1;
			b++;
		}
	}	

	return d;
}