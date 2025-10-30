#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/math>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ull> a(n);
    unordered_map<ll, vector<ll>> dict;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        dict[a[i]].push_back(i);
    }
    vector<ull> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<ll> ans(m);
    ll j = 0;
    for (ll i = 0; i < n; ++i) {
        if (j >= m) break;
        if (a[i] == b[j]) {
            ans[j] = i;
            ++j;
        }
    }
    if (j < m) {
        cout << "No" << endl;
        return 0;
    }

    vector<ll> ans2(m);
    j = m-1;
    for (ll i = n - 1; i >= 0; --i) {
        if (j < 0) break;
        if (a[i] == b[j]) {
            ans2[j] = i;
            --j;
        }
    }

    cout << (ans != ans2 ? "Yes" : "No") << endl;
    
    return 0;
}