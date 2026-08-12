#include <cassert>
#include <vector>

#include "../library/data-structures/segment-tree.hpp"

int main() {
    std::vector<long long> values = {1, 2, 3, 4, 5};

    SegmentTree seg(values);

    assert(seg.query(0, 4) == 15);
    assert(seg.query(1, 3) == 9);

    seg.update(2, 10);

    assert(seg.query(0, 4) == 22);
    assert(seg.query(2, 2) == 10);

    return 0;
}