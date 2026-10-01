#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll nxt(ll x) {
    ll s = 0;

    while (x > 0) {
        ll d = x % 10;
        s += d * d;
        x /= 10;
    }

    return s;
}

struct Info {
    int cycle;
    int phase;
    int len;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    /*
        Only very small numbers are reached after one application
        of nxt(), so we can safely memoize them.
    */

    unordered_map<ll, Info> memo;

    // cycle id:
    // 0 -> cycle {0}
    // 1 -> cycle {1}
    // 2 -> 8-cycle
    //
    // For the 8-cycle:
    // 4,16,37,58,89,145,42,20
    vector<ll> cycle8 = {
        4, 16, 37, 58, 89, 145, 42, 20
    };

    for (int i = 0; i < 8; i++) {
        memo[cycle8[i]] = {2, i, 8};
    }

    memo[0] = {0, 0, 1};
    memo[1] = {1, 0, 1};

    auto getInfo = [&](ll start) -> Info {
        if (memo.count(start))
            return memo[start];

        vector<ll> path;
        unordered_map<ll, int> pos;

        ll x = start;

        while (!memo.count(x) && !pos.count(x)) {
            pos[x] = path.size();
            path.push_back(x);
            x = nxt(x);
        }

        if (memo.count(x)) {
            /*
                We reached an already-known node.

                If the next node has key K, then the current
                node has phase K-1 (mod cycle length).
            */

            Info cur = memo[x];

            for (int i = (int)path.size() - 1; i >= 0; i--) {
                int newPhase =
                    (cur.phase - 1 + cur.len) % cur.len;

                cur.phase = newPhase;
                memo[path[i]] = cur;
            }

            return memo[start];
        }

        /*
            We found a new cycle.
        */

        int cycleStart = pos[x];
        int len = path.size() - cycleStart;

        static int nextCycleId = 3;
        int cid = nextCycleId++;

        // Assign phases to cycle nodes.
        for (int i = cycleStart; i < (int)path.size(); i++) {
            int phase = i - cycleStart;
            memo[path[i]] = {cid, phase, len};
        }

        /*
            Nodes before the cycle.
            Move backwards through the path.

            Their phase is one position before their successor.
        */
        Info cur = memo[x];

        for (int i = cycleStart - 1; i >= 0; i--) {
            cur.phase = (cur.phase - 1 + cur.len) % cur.len;
            memo[path[i]] = cur;
        }

        return memo[start];
    };

    while (T--) {
        int n;
        cin >> n;

        map<pair<int, int>, long long> cnt;

        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;

            Info info = getInfo(x);

            /*
                phase already represents the correct
                time-aligned state.

                Same (cycle, phase) => in tune.
            */
            cnt[{info.cycle, info.phase}]++;
        }

        long long ans = 0;

        for (auto &[key, c] : cnt) {
            ans += c * (c - 1) / 2;
        }

        cout << ans << '\n';
    }

    return 0;
}