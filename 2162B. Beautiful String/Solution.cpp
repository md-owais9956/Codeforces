#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        for (int mask = 0; mask < (1 << n); mask++) {
            string p = "", x = "";
            vector<int> ans;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    p += s[i];
                    ans.push_back(i + 1);
                } else {
                    x += s[i];
                }
            }

            // p must be non-decreasing
            bool ok = true;

            for (int i = 1; i < p.size(); i++) {
                if (p[i - 1] > p[i]) {
                    ok = false;
                    break;
                }
            }

            if (!ok)
                continue;

            // x must be palindrome
            if (isPalindrome(x)) {
                cout << ans.size() << '\n';

                for (int i : ans)
                    cout << i << " ";

                cout << '\n';

                ok = true;
                break;
            }
        }
    }

    return 0;
}