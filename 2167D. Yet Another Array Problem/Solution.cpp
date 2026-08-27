#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<long long> primes = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
        31, 37, 41, 43, 47, 53, 59, 61, 67, 71
    };

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (auto &x : a)
            cin >> x;

        long long answer = -1;

        for (long long p : primes) {
            bool found = false;

            for (long long x : a) {
                if (x % p != 0) {
                    found = true;
                    break;
                }
            }

            if (found) {
                answer = p;
                break;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}