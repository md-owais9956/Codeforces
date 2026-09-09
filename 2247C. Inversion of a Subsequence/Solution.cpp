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

        vector<int> a(n), b(n);

        for (int &x : a)
            cin >> x;

        for (int &x : b)
            cin >> x;

        // Already equal
        if (a == b) {
            cout << 0 << '\n';
            continue;
        }

        int onesA = 0;
        int onesB = 0;
        int wrongOnes = 0;

        for (int i = 0; i < n; i++) {
            onesA += a[i];
            onesB += b[i];

            if (a[i] != b[i] && a[i] == 1)
                wrongOnes++;
        }

        // Cannot perform any operation
        if (onesA == 0) {
            cout << -1 << '\n';
            continue;
        }

        // b is all 1s, but a != b
        if (onesB == n) {
            cout << -1 << '\n';
            continue;
        }

        // The required positions themselves form a valid operation
        if (wrongOnes % 2 == 1) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }

    return 0;
}