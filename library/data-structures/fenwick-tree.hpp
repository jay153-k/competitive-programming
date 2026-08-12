#pragma once

#include <vector>

struct FenwickTree {
    int n;
    std::vector<long long> tree;

    explicit FenwickTree(int n)
        : n(n), tree(n + 1, 0) {}

    void add(int index, long long value) {
        for (int i = index; i <= n; i += i & -i) {
            tree[i] += value;
        }
    }

    long long prefix_sum(int index) const {
        long long result = 0;

        for (int i = index; i > 0; i -= i & -i) {
            result += tree[i];
        }

        return result;
    }

    long long range_sum(int left, int right) const {
        return prefix_sum(right) - prefix_sum(left - 1);
    }
};