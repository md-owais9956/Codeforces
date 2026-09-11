#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> b(m);
        for (int &x : b)
            cin >> x;

        sort(b.begin(), b.end());

        long long ans = 0;
        int prev = 0;

        for (int x : b) {
            long long sum = 0;

            for (int j = prev + 1; j <= x; j++)
                sum += a[j];

            ans += abs(sum);
            prev = x;
        }

        for (int i = prev + 1; i <= n; i++)
            ans += a[i];

        cout << ans << '\n';
    }

    return 0;
}