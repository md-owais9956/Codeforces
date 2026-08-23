#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string r;
        cin >> r;

        int n = r.size();
        int ans = 0;

        // Boundary u's cannot remain
        if (r[0] == 'u') {
            r[0] = 's';
            ans++;
        }

        if (r[n - 1] == 'u') {
            r[n - 1] = 's';
            ans++;
        }

        // Inside the string, we cannot have two consecutive u's.
        // If r[i] and r[i+1] are both u, change one to s.
        for (int i = 1; i < n - 1; i++) {
            if (r[i] == 'u' && r[i - 1] == 'u') {
                r[i] = 's';
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}