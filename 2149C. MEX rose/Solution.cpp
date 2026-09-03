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

        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }

        int missing = 0;

        // Every number 0...k-1 must be present
        for (int x = 0; x < k; x++) {
            if (freq[x] == 0)
                missing++;
        }

        // k must not be present
        int cntK = freq[k];

        cout << max(missing, cntK) << '\n';
    }

    return 0;
}