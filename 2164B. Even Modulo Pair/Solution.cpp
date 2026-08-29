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

        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        int lim = min(n, 32);
        bool found = false;

        for (int i = 0; i < lim && !found; i++) {
            for (int j = i + 1; j < lim; j++) {
                if ((a[j] % a[i]) % 2 == 0) {
                    cout << a[i] << " " << a[j] << '\n';
                    found = true;
                    break;
                }
            }
        }

        if (!found)
            cout << -1 << '\n';
    }

    return 0;
}