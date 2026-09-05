#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve() {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int cnt0 = 0, cnt1 = 0;

        for (char c : s) {
            if (c == '0') cnt0++;
            else cnt1++;
        }

        if (abs(cnt0 - cnt1) > 2) {
            cout << -1 << '\n';
            return;
        }

        int dp[2][3];

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                dp[i][j] = -1000000;

        for (char c : s) {
            int x = c - '0';

            int ndp[2][3];

            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 3; j++)
                    ndp[i][j] = dp[i][j];

            int diff = (x == 0 ? 1 : -1);

            ndp[x][diff + 1] =
                max(ndp[x][diff + 1], 1);

            for (int last = 0; last < 2; last++) {
                if (last == x) continue;

                for (int d = -1; d <= 1; d++) {
                    if (dp[last][d + 1] < 0)
                        continue;

                    int newDiff = d + (x == 0 ? 1 : -1);

                    if (newDiff >= -1 && newDiff <= 1) {
                        ndp[x][newDiff + 1] =
                            max(ndp[x][newDiff + 1],
                                dp[last][d + 1] + 1);
                    }
                }
            }

            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 3; j++)
                    dp[i][j] = ndp[i][j];
        }

        int best = 0;
        int totalDiff = cnt0 - cnt1;

        for (int diff = -1; diff <= 1; diff++) {
            if (abs(totalDiff - diff) > 1)
                continue;

            for (int last = 0; last < 2; last++)
                best = max(best, dp[last][diff + 1]);
        }

        cout << n - best << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        Solution sol;
        sol.solve();
    }

    return 0;
}