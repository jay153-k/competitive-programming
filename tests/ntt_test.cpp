#include <cassert>
#include <vector>

#include "../library/math/ntt.hpp"

using ntt::Mint;

int main() {
    {
        std::vector<Mint> a = {1, 2};
        std::vector<Mint> b = {3, 4};

        auto result = ntt::convolution(a, b);

        // (1 + 2x)(3 + 4x)
        // = 3 + 10x + 8x^2
        assert(result.size() == 3);
        assert(result[0].value() == 3);
        assert(result[1].value() == 10);
        assert(result[2].value() == 8);
    }

    {
        std::vector<Mint> a = {1, 2, 3};
        std::vector<Mint> b = {4, 5, 6};

        auto result = ntt::convolution(a, b);

        // 4 + 13x + 28x^2 + 27x^3 + 18x^4
        std::vector<int> expected = {
            4, 13, 28, 27, 18
        };

        assert(result.size() == expected.size());

        for (int i = 0; i < static_cast<int>(expected.size()); ++i) {
            assert(result[i].value() == expected[i]);
        }
    }

    {
        std::vector<Mint> a = {5};
        std::vector<Mint> b = {7};

        auto result = ntt::convolution(a, b);

        assert(result.size() == 1);
        assert(result[0].value() == 35);
    }

    {
        std::vector<Mint> a;
        std::vector<Mint> b = {1, 2, 3};

        auto result = ntt::convolution(a, b);

        assert(result.empty());
    }

    return 0;
}