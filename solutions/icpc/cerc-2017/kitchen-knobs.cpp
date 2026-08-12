#include <bits/stdc++.h>

using namespace std;

using Triple = tuple<int, int, int>;

const int INF = 1e9;
const int MAXN = 510;

int dp[MAXN][MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> differences;
    vector<int> rotations(1, 0);

    for (int i = 1; i <= n; i++) {
        int value;
        cin >> value;

        int maximum = -1;
        int best_rotation = -1;
        bool all_same = true;

        for (int place = 1; place < 200000; place *= 10) {
            if (value / place % 10 != value / place / 10 % 10) {
                all_same = false;
            }
        }

        if (all_same) {
            continue;
        }

        for (int rotation = 0; rotation < 7; rotation++) {
            if (maximum < value) {
                maximum = value;
                best_rotation = rotation;
            }

            value = (value % 1000000 * 10 + value / 1000000);
        }

        if (best_rotation == rotations.back()) {
            continue;
        }

        rotations.push_back(best_rotation);
    }

    if (rotations.back()) {
        rotations.push_back(0);
    }

    for (int i = 0; i + 1 < static_cast<int>(rotations.size()); i++) {
        int difference = rotations[i + 1] - rotations[i];

        if (difference < 0) {
            difference += 7;
        }

        differences.push_back(difference);
    }

    int count[7]{};

    for (int difference : differences) {
        count[difference]++;
    }

    int answer = 0;

    // Pair complementary differences: (1, 6), (2, 5), (3, 4).
    for (int i = 1; i < 4; i++) {
        int pairs = min(count[i], count[7 - i]);

        answer += pairs;
        count[i] -= pairs;
        count[7 - i] -= pairs;
    }

    int remaining_types = 0;

    for (int i = 1; i < 7; i++) {
        remaining_types += (count[i] != 0);
    }

    if (remaining_types == 0) {
        cout << answer << "\n";
        return 0;
    }

    if (remaining_types == 1) {
        for (int i = 1; i < 7; i++) {
            answer += 6 * count[i] / 7;
        }

        cout << answer << "\n";
        return 0;
    }

    if (remaining_types == 2) {
        vector<int> types;

        for (int i = 1; i < 7; i++) {
            if (count[i]) {
                types.push_back(i);
            }
        }

        vector<array<int, 2>> groups;
        groups.push_back({7, 0});

        for (int first = 0; first < 7; first++) {
            for (int second = 1; second <= 7; second++) {
                if (
                    (types[0] * first + types[1] * second) % 7 == 0
                ) {
                    groups.push_back({first, second});
                }
            }
        }

        vector<vector<int>> local_dp(
            count[types[0]] + 1,
            vector<int>(count[types[1]] + 1, INF)
        );

        local_dp[0][0] = 0;

        for (int i = 0; i <= count[types[0]]; i++) {
            for (int j = 0; j <= count[types[1]]; j++) {
                for (auto [x, y] : groups) {
                    if (i >= x && j >= y) {
                        local_dp[i][j] = min(
                            local_dp[i][j],
                            local_dp[i - x][j - y] + x + y - 1
                        );
                    }
                }
            }
        }

        cout << answer
             + local_dp[count[types[0]]][count[types[1]]]
             << "\n";

        return 0;
    }

    vector<int> types;

    for (int i = 1; i < 7; i++) {
        if (count[i]) {
            types.push_back(i);
        }
    }

    vector<array<int, 3>> groups;

    groups.push_back({7, 0, 0});
    groups.push_back({0, 7, 0});

    for (int first = 0; first < 7; first++) {
        for (int second = 0; second < 7; second++) {
            if (
                (types[0] * first + types[1] * second) % 7 == 0
            ) {
                groups.push_back({
                    first,
                    second,
                    (first + second == 0 ? 7 : 0)
                });

                continue;
            }

            for (int third = 1; third < 7; third++) {
                if (
                    (
                        types[0] * first
                        + types[1] * second
                        + types[2] * third
                    ) % 7 == 0
                ) {
                    groups.push_back({first, second, third});
                }
            }
        }
    }

    for (int i = 0; i <= count[types[0]]; i++) {
        for (int j = 0; j <= count[types[1]]; j++) {
            for (int k = 0; k <= count[types[2]]; k++) {
                dp[i][j][k] =
                    (i + j + k == 0 ? 0 : INF);

                if (
                    (
                        types[0] * i
                        + types[1] * j
                        + types[2] * k
                    ) % 7
                ) {
                    continue;
                }

                for (auto [x, y, z] : groups) {
                    if (i >= x && j >= y && k >= z) {
                        dp[i][j][k] = min(
                            dp[i][j][k],
                            dp[i - x][j - y][k - z]
                                + x + y + z - 1
                        );
                    }
                }
            }
        }
    }

    cout << answer
         + dp[count[types[0]]]
             [count[types[1]]]
             [count[types[2]]]
         << "\n";

    return 0;
}