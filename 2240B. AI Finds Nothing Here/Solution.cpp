#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 998244353;

int binpow(int a, long long b) {
    int res = 1;

    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;

        long long total = n * m;
        long long constraints = (n - r + 1) * (m - c + 1);

        long long freeCells = total - constraints;

        cout << binpow(2, freeCells) << '\n';
    }

    return 0;
}