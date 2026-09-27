#include <bits/stdc++.h>
using namespace std;

bool possible(string s) {
    int n = s.size();

    // dp[p] = whether we can reach current state
    // where number of removals from left has parity p
    bool dp[2] = {true, false};

    for (int k = 0; k < n; k++) {
        bool ndp[2] = {false, false};

        for (int p = 0; p < 2; p++) {
            if (!dp[p]) continue;

            // --------------------------------
            // Option 1: Remove from the left
            // --------------------------------
            // Position = x + 1
            // If x is even -> position is odd -> 'a'
            // If x is odd  -> position is even -> 'b'
            char leftChar = (p == 0 ? 'a' : 'b');

            if (s[k] == '?' || s[k] == leftChar) {
                ndp[p ^ 1] = true;
            }

            // --------------------------------
            // Option 2: Remove from the right
            // --------------------------------
            // Position = n - k + x
            //
            // parity(position) = (n-k+p) % 2
            int posParity = (n - k + p) & 1;
            char rightChar = (posParity == 1 ? 'a' : 'b');

            if (s[k] == '?' || s[k] == rightChar) {
                ndp[p] = true;
            }
        }

        dp[0] = ndp[0];
        dp[1] = ndp[1];
    }

    return dp[0] || dp[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        string s;

        cin >> n >> s;

        cout << (possible(s) ? "YES\n" : "NO\n");
    }

    return 0;
}