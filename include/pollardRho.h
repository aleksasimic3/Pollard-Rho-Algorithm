#ifndef _POLLARD_RHO_H_
#define _POLLARD_RHO_H_

#include <cstdint>
#include <numeric>
#include <vector>

#include "millerRabin.h"

#include <iostream> //temp

//if n is composite returns non trivial divisor of n, else returns 1
uint64_t findDivisor(uint64_t n, bool skipPrimeCheck=false);
int findDivisor(int n, bool skipPrimeCheck=false);

#endif