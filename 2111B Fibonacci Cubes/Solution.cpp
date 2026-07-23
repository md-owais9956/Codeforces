#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> fib(n + 1);
        fib[0] = 1;
        fib[1] = 2;
        for (int i = 2; i <= n; i++)
            fib[i] = fib[i - 1] + fib[i - 2];

        while (m--) {
            vector<int> a(3);
            cin >> a[0] >> a[1] >> a[2];
            sort(a.begin(), a.end());

            if (a[0] >= fib[n - 1] &&
                a[1] >= fib[n - 1] &&
                a[2] >= fib[n])
                cout << '1';
            else
                cout << '0';
        }
        cout << '\n';
    }

    return 0;
}