#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
#include <ranges>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n, nq;
    cin >> n >> nq;

    atcoder::dsu d(n+nq);

    ll next = n;
    vector<ll> leaderOfBox(n);
    iota(leaderOfBox.begin(), leaderOfBox.end(), 0LL);
    vector<ll> box(n+nq);
    iota(box.begin(), box.end(), 0LL);
    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll x, y;
            cin >> x >> y;
            --x;
            --y;
            ll i = leaderOfBox[x];
            ll j = leaderOfBox[y];
            if (j == -1) continue;
            ll ni = i == -1 ? j : d.merge(i, j);
            leaderOfBox[x] = ni;
            leaderOfBox[y] = -1;
            box[ni] = x;
        } else if (type == 2) {
            ll x;
            cin >> x;
            --x;
            if (leaderOfBox[x] == -1) {
                leaderOfBox[x] = next;
                box[next] = x;
            } else {
                ll ni = d.merge(leaderOfBox[x], next);
                box[ni] = x;
            }
            ++next;
        } else {
            ll i;
            cin >> i;
            --i;
            cout << box[d.leader(i)] + 1 << endl;
        }
    }

    return 0;
}