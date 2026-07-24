#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int64> a(n + 1, 0);

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        for (int i = 1; i <= n; i++) {
            if (a[i] < a[i - 1])
                a[i] += a[i - 1];
        }

        cout << a[n] << '\n';
    }

    return 0;
}