#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> h(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int s = 0; s < n; s++) {

        vector<long long> w1(n, 0);
        vector<long long> w2(n, 0);

        // Water levels going clockwise from empty vessel s
        for (int i = 1; i < n; i++) {
            int cur = (s + i) % n;
            int prev = (s + i - 1) % n;

            w1[cur] = max(w1[prev], h[prev]);
        }

        // Water levels going counter-clockwise from empty vessel s
        for (int i = 1; i < n; i++) {
            int cur = (s + n - i) % n;
            int next = (s + n - i + 1) % n;

            w2[cur] = max(w2[next], h[cur]);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += min(w1[i], w2[i]);
        }

        cout << ans << ' ';
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}