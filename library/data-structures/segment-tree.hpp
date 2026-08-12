#pragma once

#include <vector>

struct SegmentTree {
    int n;
    std::vector<long long> tree;

    explicit SegmentTree(int n)
        : n(n), tree(4 * n, 0) {}

    explicit SegmentTree(const std::vector<long long>& values)
        : n(static_cast<int>(values.size())), tree(4 * n, 0) {
        build(1, 0, n - 1, values);
    }

    void update(int index, long long value) {
        update(1, 0, n - 1, index, value);
    }

    long long query(int left, int right) const {
        return query(1, 0, n - 1, left, right);
    }

private:
    void build(
        int node,
        int start,
        int end,
        const std::vector<long long>& values
    ) {
        if (start == end) {
            tree[node] = values[start];
            return;
        }

        int mid = (start + end) / 2;
        build(node * 2, start, mid, values);
        build(node * 2 + 1, mid + 1, end, values);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(
        int node,
        int start,
        int end,
        int index,
        long long value
    ) {
        if (start == end) {
            tree[node] = value;
            return;
        }

        int mid = (start + end) / 2;

        if (index <= mid) {
            update(node * 2, start, mid, index, value);
        } else {
            update(node * 2 + 1, mid + 1, end, index, value);
        }

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long query(
        int node,
        int start,
        int end,
        int left,
        int right
    ) const {
        if (right < start || end < left) {
            return 0;
        }

        if (left <= start && end <= right) {
            return tree[node];
        }

        int mid = (start + end) / 2;

        return query(node * 2, start, mid, left, right)
             + query(node * 2 + 1, mid + 1, end, left, right);
    }
};