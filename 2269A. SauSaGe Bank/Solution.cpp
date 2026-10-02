#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long n, k;
        cin >> n >> k;

        long long ans = 2 * (k - 1) + (1LL << (n - k + 1));

        cout << ans << '\n';
    }

    return 0;
}