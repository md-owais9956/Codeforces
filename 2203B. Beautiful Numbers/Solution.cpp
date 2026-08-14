#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string x;
        cin >> x;

        int sum = 0;

        for (char c : x) {
            sum += c - '0';
        }

        // Already beautiful
        if (sum <= 9) {
            cout << 0 << '\n';
            continue;
        }

        // How much each digit can reduce the sum
        vector<int> reduction;

        for (int i = 0; i < (int)x.size(); i++) {
            int d = x[i] - '0';

            if (i == 0) {
                // First digit cannot become 0
                reduction.push_back(d - 1);
            } else {
                // Other digits can become 0
                reduction.push_back(d);
            }
        }

        sort(reduction.rbegin(), reduction.rend());

        int need = sum - 9;
        int moves = 0;

        for (int r : reduction) {
            if (need <= 0)
                break;

            need -= r;
            moves++;
        }

        cout << moves << '\n';
    }

    return 0;
}