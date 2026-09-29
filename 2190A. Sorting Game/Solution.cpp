#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string t = s;
    sort(t.begin(), t.end());

    // Already sorted
    if (s == t) {
        cout << "Bob\n";
        return;
    }

    vector<int> ans;

    // Choose exactly the positions that are wrong
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            ans.push_back(i + 1);
        }
    }

    cout << "Alice\n";
    cout << ans.size() << '\n';

    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}