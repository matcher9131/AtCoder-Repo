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
    ll n, m, k;
    cin >> n >> m >> k;
    map<ll, ll> c;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        if (ai == 0) ai = m;
        ++c[ai];
        ++c[ai+m];
    }

    ll sum = 0;
    ll ans = 0;
    ll prevLeft = 0;
    auto itr = c.begin();
    for (auto itl = c.begin(); itl != c.end(); ++itl) {
        while (itr != c.end() && sum < k) {
            sum += itr->second;
            ++itr;
        }

        ans += (min(itl->first, m) - prevLeft) * sum;
        if (itr == itl) ++itr;
        else sum -= itl->second;
        prevLeft = itl->first;

        if (itl->first > m) break;
    }
    
    cout << ans << endl;

    return 0;
}