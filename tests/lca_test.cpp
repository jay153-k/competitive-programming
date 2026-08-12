#include <cassert>

#include "../library/graph/lca.hpp"

int main() {
    /*
            0
           / \
          1   2
         / \   \
        3   4   5
               /
              6
    */

    LCA lca(7);

    lca.add_edge(0, 1);
    lca.add_edge(0, 2);
    lca.add_edge(1, 3);
    lca.add_edge(1, 4);
    lca.add_edge(2, 5);
    lca.add_edge(5, 6);

    lca.build(0);

    assert(lca.query(3, 4) == 1);
    assert(lca.query(3, 6) == 0);
    assert(lca.query(5, 6) == 5);
    assert(lca.query(1, 4) == 1);
    assert(lca.query(2, 6) == 2);
    assert(lca.query(0, 6) == 0);

    return 0;
}