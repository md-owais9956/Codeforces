#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, int val) {
        idx++;
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int sum(int idx) {
        idx++;
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> pos(n);
        vector<bool> used(n, false);

        bool ok = true;

        for (int i = 0; i < n && ok; i++) {
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (!used[j] && b[j] >= a[i]) {
                    used[j] = true;
                    pos[i] = j;
                    found = true;
                    break;
                }
            }
            if (!found) ok = false;
        }

        if (!ok) {
            cout << -1 << '\n';
            continue;
        }

        BIT bit(n);
        long long inv = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (pos[i] > 0)
                inv += bit.sum(pos[i] - 1);
            bit.add(pos[i], 1);
        }

        cout << inv << '\n';
    }

    return 0;
}