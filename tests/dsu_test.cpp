#include <cassert>

#include "../library/data-structures/dsu.hpp"

int main() {
    DSU dsu(5);

    assert(!dsu.same(0, 1));

    assert(dsu.merge(0, 1));
    assert(dsu.merge(1, 2));

    assert(dsu.same(0, 2));
    assert(dsu.component_size(0) == 3);

    assert(!dsu.merge(0, 2));
    assert(!dsu.same(0, 3));

    return 0;
}