#pragma once

#include <algorithm>
#include <vector>

#include "modint.hpp"

namespace ntt {

constexpr int MOD = 998244353;
constexpr int PRIMITIVE_ROOT = 3;

using Mint = ModInt<MOD>;

void transform(std::vector<Mint>& a, bool invert) {
    const int n = static_cast<int>(a.size());

    // Bit-reversal permutation
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;

        while (j & bit) {
            j ^= bit;
            bit >>= 1;
        }

        j ^= bit;

        if (i < j) {
            std::swap(a[i], a[j]);
        }
    }

    // Cooley-Tukey NTT
    for (int len = 2; len <= n; len <<= 1) {
        Mint root =
            Mint(PRIMITIVE_ROOT).pow((MOD - 1) / len);

        if (invert) {
            root = root.inv();
        }

        for (int i = 0; i < n; i += len) {
            Mint w = 1;

            for (int j = 0; j < len / 2; ++j) {
                Mint u = a[i + j];
                Mint v = a[i + j + len / 2] * w;

                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;

                w *= root;
            }
        }
    }

    if (invert) {
        Mint inv_n = Mint(n).inv();

        for (Mint& x : a) {
            x *= inv_n;
        }
    }
}

std::vector<Mint> convolution(
    std::vector<Mint> a,
    std::vector<Mint> b
) {
    if (a.empty() || b.empty()) {
        return {};
    }

    const int result_size =
        static_cast<int>(a.size() + b.size() - 1);

    int n = 1;

    while (n < result_size) {
        n <<= 1;
    }

    a.resize(n);
    b.resize(n);

    transform(a, false);
    transform(b, false);

    for (int i = 0; i < n; ++i) {
        a[i] *= b[i];
    }

    transform(a, true);

    a.resize(result_size);
    return a;
}

}  // namespace ntt