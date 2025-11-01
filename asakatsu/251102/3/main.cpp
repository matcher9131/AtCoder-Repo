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
    ll nq;
    cin >> nq;

    queue<ll> que;
    ll d = 0;

    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            que.push(d);
        } else if (type == 2) {
            ll t;
            cin >> t;
            d += t;
        } else {
            ll h;
            cin >> h;
            ll count = 0;
            while (!que.empty()) {
                ll ai = que.front();
                if (d - ai < h) break;
                que.pop();
                ++count;
            }
            cout << count << "\n";
        }
    }

    return 0;
}