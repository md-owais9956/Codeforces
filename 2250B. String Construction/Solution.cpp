#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if (k == n - 1) {
            cout << -1 << '\n';
            continue;
        }

        int zeros = n / 2;
        int ones = n - zeros;

        // Start with alternating string
        string s;

        for (int i = 0; i < n; i++) {
            s += (i % 2 == 0 ? '0' : '1');
        }

        /*
          Initially k = 0.

          To create k equal adjacent pairs, we can
          extend one of the runs.

          Easier construction:
          Make the first k+1 characters equal.
        */

        if (k > 0) {
            // Need to preserve balance.
            // Construct runs directly.
            int runs = n - k;

            s = "";

            int zeroRuns = (runs + 1) / 2;
            int oneRuns = runs / 2;

            // If required runs exceed available characters,
            // start with 1 instead.
            bool startZero = true;

            if (zeroRuns > zeros || oneRuns > ones) {
                startZero = false;
                zeroRuns = runs / 2;
                oneRuns = (runs + 1) / 2;
            }

            int extraZero = zeros - zeroRuns;
            int extraOne = ones - oneRuns;

            bool addedZero = false;
            bool addedOne = false;

            for (int i = 0; i < runs; i++) {
                char c;

                if (startZero)
                    c = (i % 2 == 0 ? '0' : '1');
                else
                    c = (i % 2 == 0 ? '1' : '0');

                int len = 1;

                if (c == '0' && !addedZero) {
                    len += extraZero;
                    addedZero = true;
                }

                if (c == '1' && !addedOne) {
                    len += extraOne;
                    addedOne = true;
                }

                s += string(len, c);
            }
        }

        cout << s << '\n';
    }

    return 0;
}