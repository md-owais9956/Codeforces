#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        ll a, b, x;
        cin >> a >> b >> x;

        vector<pair<ll,int>> A, B;

        ll cur = a;
        int d = 0;
        while (true) {
            A.push_back({cur, d});
            if (cur == 0) break;
            cur /= x;
            d++;
        }

        cur = b;
        d = 0;
        while (true) {
            B.push_back({cur, d});
            if (cur == 0) break;
            cur /= x;
            d++;
        }

        ll ans = llabs(a - b);

        for (auto [va, da] : A) {
            for (auto [vb, db] : B) {
                ans = min(ans, 1LL * da + db + llabs(va - vb));
            }
        }

        cout << ans << '\n';
    }
}