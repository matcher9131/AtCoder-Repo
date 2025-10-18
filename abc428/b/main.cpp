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
    string s;
    cin >> s;

    unordered_map<string, ll> m;
    for (ll i = 0; i <= n-k; ++i) {
        ++m[s.substr(i, k)];
    }

    ll cMax = 0;
    for (const auto &[_, c] : m) {
        chmax(cMax, c);
    }
    vector<string> ans;
    for (const auto &[t, c] : m) {
        if (c == cMax) ans.push_back(t);
    }
    sort(ans.begin(), ans.end());
    
    cout << cMax << endl;
    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}