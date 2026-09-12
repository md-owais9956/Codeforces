
#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, sz;

public:
    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> p(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        DSU dsu(n);

        // Connect indices whose difference is x or y.
        for (int i = 1; i <= n; i++) {
            if (i + x <= n)
                dsu.unite(i, i + x);

            if (i + y <= n)
                dsu.unite(i, i + y);
        }

        bool possible = true;

        for (int i = 1; i <= n; i++) {
            if (!dsu.same(i, p[i])) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}