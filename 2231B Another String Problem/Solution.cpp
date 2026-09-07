#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);

        for (auto &x : a)
            cin >> x;

        // Find the minimum k that can fix every decrease
        long long k = 0;

        for (int i = 0; i + 1 < n; i++) {
            if (a[i] > a[i + 1]) {
                k = max(k, a[i] - a[i + 1]);
            }
        }

        // dp[0] = previous element was not increased
        // dp[1] = previous element was increased
        bool dp[2] = {true, true};

        for (int i = 1; i < n; i++) {
            bool ndp[2] = {false, false};

            for (int prev = 0; prev <= 1; prev++) {
                if (!dp[prev])
                    continue;

                long long prevValue = a[i - 1] + (prev ? k : 0);

                for (int cur = 0; cur <= 1; cur++) {
                    long long curValue = a[i] + (cur ? k : 0);

                    if (prevValue <= curValue) {
                        ndp[cur] = true;
                    }
                }
            }

            dp[0] = ndp[0];
            dp[1] = ndp[1];
        }

        cout << (dp[0] || dp[1] ? "YES\n" : "NO\n");
    }

    return 0;
}