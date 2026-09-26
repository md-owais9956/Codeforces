#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class MaxHeap {
    vector<ll> h;

public:
    void push(ll x) {
        h.push_back(x);
        int i = (int)h.size() - 1;

        while (i > 0) {
            int p = (i - 1) >> 1;
            if (h[p] >= h[i]) break;
            swap(h[p], h[i]);
            i = p;
        }
    }

    ll top() const {
        return h[0];
    }

    void pop() {
        int n = (int)h.size();
        h[0] = h[n - 1];
        h.pop_back();

        int i = 0;

        while (true) {
            int l = i * 2 + 1;
            int r = l + 1;
            int largest = i;

            if (l < (int)h.size() && h[l] > h[largest])
                largest = l;

            if (r < (int)h.size() && h[r] > h[largest])
                largest = r;

            if (largest == i) break;

            swap(h[i], h[largest]);
            i = largest;
        }
    }

    int size() const {
        return (int)h.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        // We need the smallest (m-1) elements
        // before the current element.
        MaxHeap heap;

        ll sum = 0;
        ll ans = LLONG_MIN;

        // Special case: m = 1
        if (m == 1) {
            cout << *max_element(a.begin(), a.end()) << '\n';
            continue;
        }

        for (int i = 0; i < n; ++i) {

            // a[i] is the last selected element.
            if (heap.size() == m - 1) {
                ll score = 1LL * m * a[i] - sum;
                ans = max(ans, score);
            }

            // Current element can now become one of
            // the first m-1 selected elements.
            heap.push(a[i]);
            sum += a[i];

            // Keep only the smallest m-1 values.
            if (heap.size() > m - 1) {
                sum -= heap.top();
                heap.pop();
            }
        }

        cout << ans << '\n';
    }

    return 0;
}