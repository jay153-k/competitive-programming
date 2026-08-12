#include <cassert>

#include "../library/data-structures/fenwick-tree.hpp"

int main() {
    FenwickTree fenwick(5);

    fenwick.add(1, 3);
    fenwick.add(2, 5);
    fenwick.add(5, 7);

    assert(fenwick.prefix_sum(1) == 3);
    assert(fenwick.prefix_sum(2) == 8);
    assert(fenwick.prefix_sum(5) == 15);

    assert(fenwick.range_sum(2, 5) == 12);

    return 0;
}