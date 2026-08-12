#pragma once

#include <vector>
#include <queue>
#include <algorithm>

class LCA {
public:
    explicit LCA(int n)
        : n(n),
          log(compute_log(n)),
          graph(n),
          depth(n, 0),
          up(n, std::vector<int>(log, 0)) {}

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void build(int root = 0) {
        std::vector<bool> visited(n, false);
        std::queue<int> q;

        visited[root] = true;
        up[root][0] = root;
        q.push(root);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i = 1; i < log; ++i) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            }

            for (int next : graph[node]) {
                if (visited[next]) {
                    continue;
                }

                visited[next] = true;
                depth[next] = depth[node] + 1;
                up[next][0] = node;
                q.push(next);
            }
        }
    }

    int query(int u, int v) const {
        if (depth[u] > depth[v]) {
            std::swap(u, v);
        }

        int diff = depth[v] - depth[u];

        for (int i = 0; i < log; ++i) {
            if (diff & (1 << i)) {
                v = up[v][i];
            }
        }

        if (u == v) {
            return u;
        }

        for (int i = log - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

private:
    int n;
    int log;
    std::vector<std::vector<int>> graph;
    std::vector<int> depth;
    std::vector<std::vector<int>> up;

    static int compute_log(int n) {
        int log = 1;

        while ((1LL << log) <= n) {
            ++log;
        }

        return log;
    }
};