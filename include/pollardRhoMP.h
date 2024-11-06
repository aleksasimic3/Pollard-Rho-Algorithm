#ifndef _POLLARD_RHO_MP_H_
#define _POLLARD_RHO_MP_H_

#include <gmp.h>
#include <gmpxx.h>
#include <numeric>
#include <string>

#include "pollardRho.h"
#include "millerRabinMP.h"

//if n is composite returns non trivial divisor, else returns 1
mpz_class findDivisor(mpz_class n, bool skipPrimeCheck=false);

#endif