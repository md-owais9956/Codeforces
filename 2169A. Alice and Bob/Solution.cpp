#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long a;
        cin >> n >> a;

        int less = 0, greater = 0;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;

            if (x < a)
                less++;
            else if (x > a)
                greater++;
        }

        if (greater > less)
            cout << a + 1 << '\n';
        else
            cout << a - 1 << '\n';
    }

    return 0;
}