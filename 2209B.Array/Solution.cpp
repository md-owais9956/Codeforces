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

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            int greater = 0;
            int smaller = 0;

            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[i])
                    greater++;
                else if (a[j] < a[i])
                    smaller++;
            }

            cout << max(greater, smaller);

            if (i + 1 < n)
                cout << ' ';
        }

        cout << '\n';
    }

    return 0;
}