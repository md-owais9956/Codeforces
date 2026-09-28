#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> p(n), a(n);

        for (int &x : p) cin >> x;
        for (int &x : a) cin >> x;

        int j = 0;
        bool ok = true;

        for (int i = 0; i < n; i++) {

            // Only process the beginning of a block
            if (i > 0 && a[i] == a[i - 1])
                continue;

            // Find a[i] in p after the previous matched element
            while (j < n && p[j] != a[i])
                j++;

            if (j == n) {
                ok = false;
                break;
            }

            j++;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}