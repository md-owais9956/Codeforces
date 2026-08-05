#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        const int NEG = -1e9;

        int dp0 = 0;      // only 2's so far
        int dp1 = NEG;    // already started keeping 1/3

        for (char c : s) {
            int ndp0 = dp0;
            int ndp1 = dp1;

            if (c == '2') {
                ndp0 = max(ndp0, dp0 + 1);
            }
            else if (c == '1' || c == '3') {
                ndp1 = max({ndp1, dp1 + 1, dp0 + 1});
            }
            // '4' is always skipped

            dp0 = ndp0;
            dp1 = ndp1;
        }

        int keep = max(dp0, dp1);
        cout << (int)s.size() - keep << '\n';
    }

    return 0;
}