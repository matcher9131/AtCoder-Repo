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
    ll n;
    cin >> n;
    vector<ll> p(n), q(n);
    for (ll i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        p[i] = x+y;
        q[i] = x-y;
    }
    
    cout << max(*max_element(p.begin(), p.end()) - *min_element(p.begin(), p.end()), *max_element(q.begin(), q.end()) - *min_element(q.begin(), q.end())) << endl;



    return 0;
}