#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> isPrime(MAXN + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i)
                isPrime[j] = false;
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        cout << (isPrime[n + 1] ? "YES" : "NO") << '\n';
    }

    return 0;
}