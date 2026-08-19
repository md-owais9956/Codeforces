#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;

        cin >> n >> s;

        int ones = count(s.begin(), s.end(), '1');

        if (ones == 0) {
            cout << (n + 2) / 3 << '\n';
            continue;
        }

        int ans = ones;

        for (int i = 0; i < n; ) {
            if (s[i] == '1') {
                i++;
                continue;
            }

            int start = i;

            while (i < n && s[i] == '0')
                i++;

            int len = i - start;

            if (start > 0 && i < n) {
                // Between two existing 1s
                ans += max(0, (len - 2 + 2) / 3);
            } else {
                // Prefix or suffix
                ans += max(0, (len - 1 + 2) / 3);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}