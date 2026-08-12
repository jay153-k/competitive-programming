#include <cassert>

#include "../library/math/modint.hpp"

using Mint = ModInt<998244353>;

int main() {
    Mint a = 10;
    Mint b = 20;

    assert((a + b).value() == 30);
    assert((b - a).value() == 10);
    assert((a * b).value() == 200);

    Mint c = -1;
    assert(c.value() == 998244352);

    Mint d = 998244354;
    assert(d.value() == 1);

    assert(Mint(2).pow(10).value() == 1024);

    Mint x = 7;
    assert((x * x.inv()).value() == 1);

    Mint y = 123456;
    assert((y / y).value() == 1);

    return 0;
}