#include <cassert>
#include <vector>

#include "../library/math/sieve.hpp"

int main() {
    Sieve sieve(20);

    assert(sieve[2]);
    assert(sieve[3]);
    assert(!sieve[4]);
    assert(sieve[19]);
    assert(!sieve[20]);

    const std::vector<int> expected = {2, 3, 5, 7, 11, 13, 17, 19};
    assert(sieve.get_primes() == expected);

    return 0;
}