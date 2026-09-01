#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        // If there is no B, every operation is a--.
        bool hasB = false;
        for (char c : s) {
            if (c == 'B') {
                hasB = true;
                break;
            }
        }

        while (q--) {
            long long a;
            cin >> a;

            if (!hasB) {
                // Only A machines exist.
                cout << a << ' ';
                continue;
            }

            long long ans = 0;
            int pos = 0;

            while (a > 0) {
                if (s[pos] == 'A') {
                    a--;
                } else {
                    a /= 2;
                }

                ans++;

                pos++;
                if (pos == n)
                    pos = 0;
            }

            cout << ans << ' ';
        }

        cout << '\n';
    }

    return 0;
}