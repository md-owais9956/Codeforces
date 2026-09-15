#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n <= 1) {
        cout << n << "\n";
        return;
    }

    int count0 = 0;
    int count1 = 0;
    for (char c : s) {
        if (c == '0') count0++;
        else count1++;
    }

    if (count0 == 0 || count1 == 0) {
        cout << 1 << "\n";
        return;
    }

    bool is_non_decreasing = is_sorted(s.begin(), s.end());
    bool is_non_increasing = is_sorted(s.rbegin(), s.rend());

    if (is_non_decreasing || is_non_increasing) {
        cout << 2 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}