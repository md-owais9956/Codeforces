#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        // Block 1
        for (int i = 1; i <= n; i++) cout << i << ' ';

        // Block 2
        for (int i = 1; i <= n; i++) cout << i << ' ';

        // Block 3 (left rotation)
        for (int i = 2; i <= n; i++) cout << i << ' ';
        cout << 1 << ' ';

        // Block 4
        for (int i = 1; i <= n; i++) cout << i << ' ';

        cout << '\n';
    }

    return 0;
}