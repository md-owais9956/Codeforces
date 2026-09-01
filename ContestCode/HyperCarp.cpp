#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    // dp[0]: max length ending at color c without using any swap
    // dp[1]: max length with swap operation in progress / active
    // dp[2]: max length with swap operation completed
    // We maintain best values per last-color to enforce adjacent element color inequality.

    int base_len = 1;
    vector<int> compressed;
    compressed.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            compressed.push_back(a[i]);
        }
    }
    
    int ans = compressed.size();

    // Check potential bonus from swapping
    // A single adjacent swap can resolve at most 1 conflict, giving at most +1 length 
    // over the non-swapped compressed sequence.
    // However, if the compressed sequence has potential swap windows (e.g. pattern like X, Y, X, Y or repeated characters in original array),
    // we check if we can get base_len + 1.

    bool can_extend = false;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) {
            can_extend = true;
            break;
        }
    }

    if (can_extend) {
        ans = max(ans, (int)compressed.size() + 1);
    }

    // Cap the answer by total array size n
    ans = min(ans, n);

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TestsNumT;
    if (cin >> TestsNumT) {
        while (TestsNumT--) {
            solve();
        }
    }
    return 0;
}