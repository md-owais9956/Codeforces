#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n), b(m);

        for (auto &x : a)
            cin >> x;

        for (auto &x : b)
            cin >> x;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        bool ok = true;

        // Every b needs at least 2 original elements
        if (n < 2 * m) {
            ok = false;
        } else {
            for (int i = 0; i < m; i++) {
                if (b[i] < a[i] || b[i] > a[n - m + i]) {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}