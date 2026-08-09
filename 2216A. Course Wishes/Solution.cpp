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

        vector<int> a(k + 1);

        for (int i = 1; i <= k; i++) {
            cin >> a[i];
        }

        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<int> ans;

        // Process levels from k down to 1
        for (int level = k; level >= 1; level--) {

            for (int i = 0; i < n; i++) {

                if (b[i] == level) {

                    // Move this course all the way to k+1
                    while (b[i] <= k) {
                        ans.push_back(i + 1);
                        b[i]++;
                    }
                }
            }
        }

        cout << ans.size() << '\n';

        for (int x : ans) {
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}