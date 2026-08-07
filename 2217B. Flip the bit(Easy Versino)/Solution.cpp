#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int p;
        cin >> p;
        --p;

        int x = a[p];
        vector<int> b(n);

        for (int i = 0; i < n; i++)
            b[i] = a[i] ^ x;

        int fl = b[0];
        for (int i = 0; i < p; i++)
            if (b[i] != b[i + 1])
                fl++;

        int fr = b[n - 1];
        for (int i = p; i < n - 1; i++)
            if (b[i] != b[i + 1])
                fr++;

        int ans = max(fl, fr);
        if (ans & 1) ans++;

        cout << ans << '\n';
    }

    return 0;
}