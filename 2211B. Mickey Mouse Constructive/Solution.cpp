
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 676767677;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        int d = abs(x - y);

        ll ans = 1;

        if (d == 0) {
            ans = 1;
        } else {
            ans = 0;

            for (int i = 1; 1LL * i * i <= d; i++) {
                if (d % i == 0) {
                    ans++;

                    if (i != d / i) {
                        ans++;
                    }
                }
            }
        }

        cout << ans % MOD << '\n';

        if (x >= y) {
            for (int i = 0; i < y; i++) {
                cout << -1 << " ";
            }

            for (int i = 0; i < x; i++) {
                cout << 1 << " ";
            }
        } else {
            for (int i = 0; i < x; i++) {
                cout << 1 << " ";
            }

            for (int i = 0; i < y; i++) {
                cout << -1 << " ";
            }
        }

        cout << '\n';
    }

    return 0;
}