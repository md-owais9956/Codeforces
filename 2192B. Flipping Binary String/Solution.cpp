#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int ones = count(s.begin(), s.end(), '1');

        if (n % 2 == 1 && ones % 2 == 1) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> ans;

        if (ones % 2 == 0) {
            // Select all 1s
            for (int i = 0; i < n; i++) {
                if (s[i] == '1')
                    ans.push_back(i + 1);
            }
        } else {
            // n must be even here.
            // Select all 0s
            for (int i = 0; i < n; i++) {
                if (s[i] == '0')
                    ans.push_back(i + 1);
            }
        }

        cout << ans.size() << '\n';

        for (int i : ans)
            cout << i << ' ';

        cout << '\n';
    }

    return 0;
}