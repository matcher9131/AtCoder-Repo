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
    vector<ll> rev(n, -1);
    ll j = -1;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        --ai;
        if (ai < 0) j = i;
        else rev[ai] = i;
    }

    vector<ll> ans;
    while (j >= 0) {
        ans.push_back(j);
        j = rev[j];
    }
    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i]+1 << " \n"[i == (ll)ans.size() - 1];
    }
    

    return 0;
}