#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        int ans = 0;

        for (int i = 0; i + 1 < n; i++) {
            int d = abs(p[i] - p[i + 1]);
            int mn = min(p[i], p[i + 1]);

            if (mn % d == 0)
                ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}