#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        bool ok = false;
        int two = 0;

        for (int i = 0; i < k; i++) {
            long long x;
            cin >> x;
            if (x >= 3) ok = true;
            if (x >= 2) two++;
        }

        if (ok || two >= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}