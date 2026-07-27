#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long budget = n;
        long long eligible = min(k, budget);

        long long ans = eligible;
        budget -= eligible;

        long long cost = 2;

        while (eligible > 0 && budget >= cost) {
            long long buy = min(eligible, budget / cost);
            ans += buy;
            budget -= buy * cost;
            eligible = buy;
            cost <<= 1;
        }

        cout << ans << '\n';
    }

    return 0;
}