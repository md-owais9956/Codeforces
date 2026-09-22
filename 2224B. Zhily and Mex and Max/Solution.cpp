#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int mx = 0;

    for (int &x : a) {
        cin >> x;
        mx = max(mx, x);
    }

    sort(a.begin(), a.end());

    int mex = 0;

    for (int x : a) {
        if (x == mex) {
            mex++;
        }
    }

    ll ans = 1LL * mx * n;

    ans += 1LL * mex * (mex + 1) / 2;

    ans += 1LL * (n - mex - 1) * mex;

    // Special case: mex = mx + 1
    if (mex == mx + 1) {
        ans += mex - mx;
    }

    cout << ans << '\n';
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