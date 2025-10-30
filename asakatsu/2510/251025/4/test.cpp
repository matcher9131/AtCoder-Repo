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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_set<ll> ans;
    for (ll i = 0; i < n; ++i) {
        while (a[i] > 0) {
            ans.insert(a[i]);
            a[i] >>= 1;
        }
    }
    cout << ans.size() << endl;

    return 0;
}