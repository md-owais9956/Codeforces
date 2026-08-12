#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll lcm_ll(ll a, ll b) {
    return (a / std::gcd(a, b)) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll a, b, c, m;
        cin >> a >> b >> c >> m;

        ll ab = lcm_ll(a, b);
        ll ac = lcm_ll(a, c);
        ll bc = lcm_ll(b, c);
        ll abc = lcm_ll(ab, c);

        ll A = m / a;
        ll B = m / b;
        ll C = m / c;

        ll AB = m / ab;
        ll AC = m / ac;
        ll BC = m / bc;
        ll ABC = m / abc;

        ll alice = 6 * A - 3 * AB - 3 * AC + 2 * ABC;
        ll bob   = 6 * B - 3 * AB - 3 * BC + 2 * ABC;
        ll carol = 6 * C - 3 * AC - 3 * BC + 2 * ABC;

        cout << alice << " " << bob << " " << carol << '\n';
    }

    return 0;
}