#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long pref = 0;
        long long ans = LLONG_MAX;

        for (int i = 1; i <= n; i++) {
            long long x;
            cin >> x;
            pref += x;
            ans = min(ans, pref / i);
            cout << ans << " ";
        }
        cout << "\n";
    }

    return 0;
}