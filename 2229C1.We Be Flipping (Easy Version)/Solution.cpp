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
        for (auto &x : a)
            cin >> x;

        vector<int> ans;
        bool flip = false;

        for (int i = n - 1; i >= 0; --i) {

            // Current effective value after previous flips
            long long x = flip ? -a[i] : a[i];

            if (x > 0) {
                ans.push_back(i + 1);
                flip = !flip;
            }
        }

        cout << ans.size() << '\n';

        for (int x : ans)
            cout << x << ' ';

        cout << '\n';
    }

    return 0;
}