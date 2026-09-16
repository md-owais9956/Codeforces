#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x;
        cin >> x;

        int digits = to_string(x).size();

        long long p = 1;
        for (int i = 0; i < digits; i++)
            p *= 10;

        cout << p + 1 << '\n';
    }

    return 0;
}