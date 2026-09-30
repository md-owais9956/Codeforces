#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    
    // Difference array to mark covered forbidden intervals in O(N)
    vector<int> diff(n + 1, 0);

    for (int k = 1; k <= n; ++k) {
        cin >> a[k];
        
        long long L = 1LL * a[k] * k;
        long long R = 1LL * (a[k] + 1) * k - 1;

        if (L < n) {
            int start = (int)L;
            int end = (int)min((long long)n - 1, R);
            
            diff[start]++;
            diff[end + 1]--;
        }
    }

    // Prefix sum to get forbidden status for each y in [0, n-1]
    vector<int> B;
    B.reserve(n);
    
    int current_coverage = 0;
    for (int y = 0; y < n; ++y) {
        current_coverage += diff[y];
        if (current_coverage == 0) {
            B.push_back(y);
        }
    }

    // Output results
    cout << B.size() << "\n";
    for (size_t i = 0; i < B.size(); ++i) {
        cout << B[i] << (i + 1 == B.size() ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}