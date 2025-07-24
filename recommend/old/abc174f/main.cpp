#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, nq;
    cin >> n >> nq;
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
        --c[i];
    }
    vector<tuple<ll, ll, ll>> q(nq);
    for (ll i = 0; i < nq; ++i) {
        ll l, r;
        cin >> l >> r;
        --l;
        --r;
        q[i] = { l, r + 1, i };
    }
    ll blockLength = ceil(n / sqrt(nq));
    sort(q.begin(), q.end(), [&](tuple<ll, ll, ll> &a, tuple<ll, ll, ll> &b) {
        auto [al, ar, ai] = a;
        auto [bl, br, bi] = b;
        ll blockA = al / blockLength;
        ll blockB = bl / blockLength;
        if (blockA == blockB) return ar < br;
        else return blockA < blockB;
    });

    vector<ll> ans(nq);
    vector<ll> count(n);
    ll cl = 0, cr = 0;
    ll size = 0;
    for (const auto &[l, r, i] : q) {
        while (cr < r) {
            if (count[c[cr]] == 0) ++size;
            ++count[c[cr]];
            ++cr;
        }
        while (cl > l) {
            --cl;
            if (count[c[cl]] == 0) ++size;
            ++count[c[cl]];
        }
        while (cr > r) {
            --cr;
            --count[c[cr]];
            if (count[c[cr]] == 0) --size;
        }
        while (cl < l) {
            --count[c[cl]];
            if (count[c[cl]] == 0) --size;
            ++cl;
        }
        ans[i] = size;
    }

    for (ll i = 0; i < nq; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}