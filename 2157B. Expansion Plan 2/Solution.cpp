#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;

        string s;
        cin >> s;

        long long cnt4 = 0, cnt8 = 0;

        for (char c : s) {
            if (c == '4')
                cnt4++;
            else
                cnt8++;
        }

        long long needX = max(0LL, abs(x) - cnt8);
        long long needY = max(0LL, abs(y) - cnt8);

        if (needX + needY <= cnt4)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}