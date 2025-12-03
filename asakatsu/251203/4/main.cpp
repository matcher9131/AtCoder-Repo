#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll h, w, i, j;
    cin >> h >> w >> i >> j;
    --i;
    --j;
    ll n;
    cin >> n;
    unordered_map<ll, set<ll>> wr, wc;
    for (ll wi = 0; wi < n; ++wi) {
        ll ri, ci;
        cin >> ri >> ci;
        --ri;
        --ci;
        wr[ri].insert(ci);
        wc[ci].insert(ri);
    }
    //番兵
    for (auto &[_, s] : wr) {
        s.insert(-1);
        s.insert(w);
    }
    for (auto &[_, s] : wc) {
        s.insert(-1);
        s.insert(h);
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        char d;
        ll l;
        cin >> d >> l;
        if (d == 'L') {
            if (wr.contains(i)) {
                auto it = wr[i].lower_bound(j);
                --it;
                j = max(*it + 1, j-l);
                j = max(0LL, j);
            } else {
                j = max(0LL, j-l);
            }
        } else if (d == 'R') {
            if (wr.contains(i)) {
                auto it = wr[i].lower_bound(j);
                j = min(*it - 1, j+l);
                j = min(w-1, j);
            } else {
                j = min(w-1, j+l);
            }
        } else if (d == 'U') {
            if (wc.contains(j)) {
                auto it = wc[j].lower_bound(i);
                --it;
                i = max(*it + 1, i-l);
                i = max(0LL, i);
            } else {
                i = max(0LL, i-l);
            }
        } else {
            if (wc.contains(j)) {
                auto it = wc[j].lower_bound(i);
                i = min(*it - 1, i+l);
                i = min(h-1, i);
            } else {
                i = min(h-1, i+l);
            }
        }
        cout << i+1 << " " << j+1 << "\n";
    }

    return 0;
}