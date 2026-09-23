
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<long long> odd, even;
    long long total = 0;

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;

        total += x;

        if (i % 2 == 1)
            odd.push_back(x);
        else
            even.push_back(x);
    }

    int oddCount = 0, evenCount = 0;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        if (x % 2 == 1)
            oddCount++;
        else
            evenCount++;
    }

    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());

    long long markedSum = 0;

    auto calculate = [&](vector<long long>& v, int k) -> long long {
        if (k == 0) return 0;

        long long sum = 0;
        int positiveCount = 0;

        for (long long x : v) {
            if (x > 0 && positiveCount < k) {
                sum += x;
                positiveCount++;
            }
        }

        // If there are no positive elements,
        // mark the largest (least negative) element once.
        if (positiveCount == 0) {
            return v[0];
        }

        return sum;
    };

    markedSum += calculate(odd, oddCount);
    markedSum += calculate(even, evenCount);

    cout << total - markedSum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}