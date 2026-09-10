#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long c;
        cin >> n >> c;

        vector<long long> a(n);
        long long ans = 0;

        for (long long &x : a) {
            cin >> x;
            ans += x;
        }

        // All elements taken individually
        ans -= 1LL * n * c;

        sort(a.begin(), a.end());

        // Improve the answer by creating pairs
        for (int i = 0; i < n / 2; i++) {
            long long gain = c - a[i];

            if (gain <= 0)
                break;

            ans += gain;
        }

        cout << ans << '\n';
    }

    return 0;
}