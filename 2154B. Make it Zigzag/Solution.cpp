#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        ll ans = 0;

        // First pair: a[0] < a[1]
        if (a[0] >= a[1])
            ans++;

        ll mx = max(a[0], a[1]);

        // Odd 1-indexed positions: 3,5,7,...
        // These are indices 2,4,6,... in 0-indexing.
        for (int i = 2; i < n; i++) {
            if (i % 2 == 0) {
                if (a[i] >= mx) {
                    ans += a[i] - mx + 1;
                }
            }

            mx = max(mx, a[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}