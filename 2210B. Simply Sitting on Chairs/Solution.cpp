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

        vector<int> p(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        vector<int> prefix(n + 1, 0);

        // prefix[i] = number of positions j <= i
        // for which p[j] <= j
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1];

            if (p[i] <= i) {
                prefix[i]++;
            }
        }

        int ans = prefix[n];

        // Try choosing a position i where p[i] is in the future
        for (int i = 1; i <= n; i++) {
            if (p[i] > i) {
                ans = max(ans, prefix[p[i] - 1] + 1);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}