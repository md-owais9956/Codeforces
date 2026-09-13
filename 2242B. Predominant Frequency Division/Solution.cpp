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

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<int> pref1(n + 1, 0);
        vector<int> pref2(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            pref1[i] = pref1[i - 1];
            pref2[i] = pref2[i - 1];

            if (a[i] == 1) {
                pref1[i]++;
                pref2[i]++;
            } else if (a[i] == 2) {
                pref1[i]--;
                pref2[i]++;
            } else {
                pref1[i]--;
                pref2[i]--;
            }
        }

        // Only endpoints j <= n-1 are allowed.
        vector<int> suf(n + 2, INT_MIN);

        suf[n - 1] = pref2[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            suf[i] = max(pref2[i], suf[i + 1]);
        }

        bool possible = false;

        // i is the end of the left part.
        // j is the end of the middle part.
        for (int i = 1; i <= n - 2; i++) {
            // Left part must be valid.
            if (pref1[i] < 0) {
                continue;
            }

            // Find j in [i+1, n-1] such that
            // pref2[j] >= pref2[i].
            if (suf[i + 1] >= pref2[i]) {
                possible = true;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}