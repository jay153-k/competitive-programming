#pragma once

#include <numeric>
#include <vector>

struct DSU {
    std::vector<int> parent;
    std::vector<int> size;

    explicit DSU(int n)
        : parent(n), size(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return false;
        }

        if (size[x] < size[y]) {
            std::swap(x, y);
        }

        parent[y] = x;
        size[x] += size[y];
        return true;
    }

    int component_size(int x) {
        return size[find(x)];
    }
};