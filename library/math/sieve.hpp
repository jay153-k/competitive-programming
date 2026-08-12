#pragma once

#include <vector>

class Sieve {
public:
    explicit Sieve(int n)
        : is_prime(n + 1, true) {
        if (n >= 0) is_prime[0] = false;
        if (n >= 1) is_prime[1] = false;

        for (int i = 2; i <= n; ++i) {
            if (!is_prime[i]) {
                continue;
            }

            primes.push_back(i);

            if (1LL * i * i > n) {
                continue;
            }

            for (long long j = 1LL * i * i; j <= n; j += i) {
                is_prime[static_cast<int>(j)] = false;
            }
        }
    }

    bool operator[](int x) const {
        return is_prime[x];
    }

    const std::vector<int>& get_primes() const {
        return primes;
    }

private:
    std::vector<bool> is_prime;
    std::vector<int> primes;
};