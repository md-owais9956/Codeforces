
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve() {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        vector<int> dp(n + 1, 1e9);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {

            // Option 1: Vertical pair
            int verticalCost = (a[i] != b[i]);

            dp[i + 1] = min(
                dp[i + 1],
                dp[i] + verticalCost
            );

            // Option 2: Horizontal pairs
            if (i + 1 < n) {

                int horizontalCost =
                    (a[i] != a[i + 1]) +
                    (b[i] != b[i + 1]);

                dp[i + 2] = min(
                    dp[i + 2],
                    dp[i] + horizontalCost
                );
            }
        }

        cout << dp[n] << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        Solution obj;
        obj.solve();
    }

    return 0;
}