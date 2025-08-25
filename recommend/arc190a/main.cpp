#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

using S = ll;
S op(S a, S b) {
    return max(a, b);
}
S e() {
    return -1;
}


int main() {
    ll n, m;
    cin >> n >> m;
    // li, ri, i
    vector<tuple<ll, ll, ll>> seg(m);
    int single = -1;
    for (ll i = 0; i < m; ++i) {
        ll li, ri;
        cin >> li >> ri;
        --li;
        --ri;
        seg[i] = { li, ri, i };
        if (li == 0 && ri == n-1) single = i;
    }

    if (single != -1) {
        cout << 1 << endl;
        for (ll mi = 0; mi < m; ++mi) {
            cout << (mi == single ? 1 : 0) << " \n"[mi == m - 1];
        }
        return 0;
    }

    sort(seg.begin(), seg.end(), [](tuple<ll, ll, ll> &a, tuple<ll, ll, ll> &b) {
        auto [la, ra, _ai] = a;
        auto [lb, rb, _bi] = b;
        return ra == rb ? la > lb : ra < rb;
    });

    atcoder::segtree<S, op, e> segL(n), segR(n);
    for (const auto &[li, ri, i] : seg) {
        ll j1 = segR.prod(0, li);
        if (j1 >= 0) {
            // rj < li（共通部分なし）
            cout << 2 << endl;
            for (ll mi = 0; mi < m; ++mi) {
                cout << (mi == i || mi == j1 ? 2 : 0) << " \n"[mi == m - 1];
            }
            return 0;
        }
        ll j2 = segL.prod(li, ri + 1);
        if (j2 >= 0) {
            // li <= lj <= ri（iがjを包含）
            cout << 2 << endl;
            for (ll mi = 0; mi < m; ++mi) {
                cout << (mi == i ? 1 : mi == j2 ? 2 : 0) << " \n"[mi == m - 1];
            }
            return 0;
        }
        segL.set(li, i);
        segR.set(ri, i);
    }

    ll l0rMax = -1, l0rMaxIndex = -1, rNlMin = n, rNlMinIndex = -1;
    for (const auto &[li, ri, i] : seg) {
        if (li == 0) {
            if (ri > l0rMax) {
                l0rMax = ri;
                l0rMaxIndex = i;
            }
        }
        if (ri == n-1) {
            if (li < rNlMin) {
                rNlMin = li;
                rNlMinIndex = i;
            }
        }
    }
    if (l0rMaxIndex >= 0 && rNlMinIndex >= 0) {
        cout << 2 << endl;
        for (ll mi = 0; mi < m; ++mi) {
            cout << (mi == l0rMaxIndex || mi == rNlMinIndex ? 1 : 0) << " \n"[mi == m - 1];
        }
        return 0;
    }

    if (m <= 2) {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> ans(m);
    ans[get<2>(seg[0])] = 1;
    ans[get<2>(seg[1])] = 2;
    ans[get<2>(seg[2])] = 1;
    cout << 3 << endl;
    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}