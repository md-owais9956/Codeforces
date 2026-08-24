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

        int ans = 0;
        int cur = 0;

        for (int i = 0; i < 2 * n; i++) {
            if (s[i % n] == '0') {
                cur++;
                ans = max(ans, cur);
            } else {
                cur = 0;
            }

            if (cur == n)
                break;
        }

        cout << ans << '\n';
    }

    return 0;
}