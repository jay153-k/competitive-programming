#include <cassert>
#include <vector>

#include "../library/math/fft.hpp"

int main() {
    {
        std::vector<long long> a = {1, 2};
        std::vector<long long> b = {3, 4};

        auto result = fft::convolution(a, b);

        // (1 + 2x)(3 + 4x)
        // = 3 + 10x + 8x^2
        std::vector<long long> expected = {
            3, 10, 8
        };

        assert(result == expected);
    }

    {
        std::vector<long long> a = {1, 2, 3};
        std::vector<long long> b = {4, 5, 6};

        auto result = fft::convolution(a, b);

        std::vector<long long> expected = {
            4, 13, 28, 27, 18
        };

        assert(result == expected);
    }

    {
        std::vector<long long> a = {5};
        std::vector<long long> b = {7};

        auto result = fft::convolution(a, b);

        assert(result.size() == 1);
        assert(result[0] == 35);
    }

    {
        std::vector<long long> a;
        std::vector<long long> b = {1, 2, 3};

        auto result = fft::convolution(a, b);

        assert(result.empty());
    }

    {
        std::vector<long long> a = {
            -1, 2, -3
        };

        std::vector<long long> b = {
            4, -5
        };

        auto result = fft::convolution(a, b);

        // (-1 + 2x - 3x^2)(4 - 5x)
        // = -4 + 13x - 22x^2 + 15x^3

        std::vector<long long> expected = {
            -4, 13, -22, 15
        };

        assert(result == expected);
    }

    return 0;
}