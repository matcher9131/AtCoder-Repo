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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> c{2,5,5,4,5,6,3,7,6};

    auto isBigger = [](string &s, string &t) -> bool {
        if (s.size() > t.size()) return true;
        else if (s.size() == t.size()) return s > t;
        else return false;
    };

    vector<string> dp(n+1);
    for (const ll ai : a) {
        string ns = to_string(ai+1);
        if (isBigger(ns, dp[c[ai]])) dp[c[ai]] = ns;
    }
    for (ll i = 1; i <= n; ++i) {
        if (dp[i] == "") continue;
        for (const ll ai : a) {
            if (i + c[ai] > n) continue;
            string ns = dp[i] + to_string(ai + 1);
            if (isBigger(ns, dp[i + c[ai]])) dp[i + c[ai]] = ns;
        }
    }
    cout << dp[n] << endl;

    return 0;
}