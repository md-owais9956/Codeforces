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

        long long evenSum = 0;
        vector<long long> odd;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;

            if (x % 2 == 0)
                evenSum += x;
            else
                odd.push_back(x);
        }

        // No odd field => mower can never turn on
        if (odd.empty()) {
            cout << 0 << '\n';
            continue;
        }

        // We can cut ceil(number of odd fields / 2)
        // Choose the largest ones.
        sort(odd.rbegin(), odd.rend());

        int take = (odd.size() + 1) / 2;

        long long ans = evenSum;

        for (int i = 0; i < take; i++) {
            ans += odd[i];
        }

        cout << ans << '\n';
    }

    return 0;
}