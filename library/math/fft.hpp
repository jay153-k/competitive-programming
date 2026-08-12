#pragma once

#include <algorithm>
#include <cmath>
#include <complex>
#include <vector>

namespace fft {

using Complex = std::complex<double>;

constexpr double PI = 3.14159265358979323846;

void transform(std::vector<Complex>& a, bool invert) {
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

    // Cooley-Tukey FFT
    for (int len = 2; len <= n; len <<= 1) {
        const double angle =
            2.0 * PI / len * (invert ? -1.0 : 1.0);

        const Complex root(std::cos(angle), std::sin(angle));

        for (int i = 0; i < n; i += len) {
            Complex w = 1.0;

            for (int j = 0; j < len / 2; ++j) {
                Complex u = a[i + j];
                Complex v = a[i + j + len / 2] * w;

                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;

                w *= root;
            }
        }
    }

    if (invert) {
        for (Complex& x : a) {
            x /= n;
        }
    }
}

std::vector<long long> convolution(
    const std::vector<long long>& a,
    const std::vector<long long>& b
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

    std::vector<Complex> fa(a.begin(), a.end());
    std::vector<Complex> fb(b.begin(), b.end());

    fa.resize(n);
    fb.resize(n);

    transform(fa, false);
    transform(fb, false);

    for (int i = 0; i < n; ++i) {
        fa[i] *= fb[i];
    }

    transform(fa, true);

    std::vector<long long> result(result_size);

    for (int i = 0; i < result_size; ++i) {
        result[i] = std::llround(fa[i].real());
    }

    return result;
}

}  // namespace fft