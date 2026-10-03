#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long ans = 0;
        vector<long long> v;

        // Middle elements are forced to be deleted
        for (int i = 0; i < n; i++) {
            if (i >= k - 1 && i <= n - k) {
                ans += a[i];
            } else {
                v.push_back(a[i]);
            }
        }

        // Number of symmetric pairs from which
        // exactly one element must be deleted
        int cnt = max(0, (int)v.size() - (k - 1));

        int l = 0;
        int r = (int)v.size() - 1;

        while (cnt--) {
            ans += max(v[l], v[r]);
            l++;
            r--;
        }

        cout << ans << '\n';
    }

    return 0;
}