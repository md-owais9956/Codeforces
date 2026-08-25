#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    // Handle the endpoints first
    if (a[0] == -1 && a[n - 1] == -1) {
        a[0] = a[n - 1] = 0;
    }
    else if (a[0] == -1) {
        a[0] = a[n - 1];
    }
    else if (a[n - 1] == -1) {
        a[n - 1] = a[0];
    }

    // All internal blanks should be 0
    for (int i = 1; i < n - 1; i++) {
        if (a[i] == -1)
            a[i] = 0;
    }

    cout << abs(a[n - 1] - a[0]) << '\n';

    for (int x : a)
        cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solution();
    }

    return 0;
}