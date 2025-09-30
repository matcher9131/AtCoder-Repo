#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll h, w, nq;
    cin >> h >> w >> nq;

    vector<pair<ll, tuple<ll, ll, ll>>> query(nq);
    for (ll qi = 0; qi < nq; ++qi) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll l, r, x;
            cin >> l >> r >> x;
            --l;
            query[qi] = {type, {l, r, x}};
        } else if (type == 2) {
            ll i, x;
            cin >> i >> x;
            --i;
            query[qi] = {type, {i, x, -1}};
        } else {
            ll i, j;
            cin >> i >> j;
            --i;
            --j;
            query[qi] = {type, {i, j, -1}};
        }
    }

    vector<ll> latest2qi(h);
    vector<unordered_set<ll>> shouldMemorizeCols(nq);
    for (ll qi = 0; qi < nq; ++qi) {
        if (query[qi].first == 2) {
            auto [i, x, _] = query[qi].second;
            latest2qi[i] = qi;
        } else if (query[qi].first == 3) {
            auto [i, j, _] = query[qi].second;
            ll qj = latest2qi[i];
            shouldMemorizeCols[qj].insert(j);
        }
    }

    // key = [i, j], value = [sum, newValue]
    map<pair<ll, ll>, pair<ll, ll>> memo;
    atcoder::fenwick_tree<ll> fw(w+1);
    for (ll qi = 0; qi < nq; ++qi) {
        if (query[qi].first == 1) {
            auto [l, r, x] = query[qi].second;
            fw.add(l, x);
            fw.add(r, -x);
        } else if (query[qi].first == 2) {
            auto [i, x, _] = query[qi].second;
            for (const ll j : shouldMemorizeCols[qi]) {
                memo[{i,j}] = { fw.sum(0, j+1), x };
            }
        } else {
            auto [i, j, _] = query[qi].second;
            if (memo.contains({i,j})) {
                auto [s, x] = memo[{i,j}];
                cout << fw.sum(0, j+1) - s + x << endl;
            } else {
                cout << fw.sum(0, j+1) << endl;
            }
        }
    }


    return 0;
}