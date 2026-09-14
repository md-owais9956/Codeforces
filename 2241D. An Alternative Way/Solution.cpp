#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = n - 1; i >= 1; i--) {
        if (a[i] > b[i]) {
            int diff = a[i] - b[i];

            a[i] -= diff;
            a[i - 1] += diff;
        }
    }

    if (a[0] <= b[0])
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}