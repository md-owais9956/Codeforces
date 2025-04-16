#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnosol = 0;

    vector<vector<int>> x(n, vector<int>(3)); // 2D vector to store all inputs

    for (int i = 0; i < n; i++) {
        cin >> x[i][0] >> x[i][1] >> x[i][2];
    }

    for (int i = 0; i < n; i++) {
        int cyes = 0;
        for (int j = 0; j < 3; j++) {
            if (x[i][j] == 1) {
                cyes++;
            }
        }
        if (cyes > 1) {
            cnosol++;
        }
    }

    cout << cnosol;

    return 0;
}
