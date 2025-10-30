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
    string s, t;
    cin >> s >> t;
    ll sLen = s.size();

    vector<vector<ll>> m(26);
    for (ll i = 0; i < (ll)s.size(); ++i) {
        m[s[i] - 'a'].push_back(i);
    }
    for (ll i = 0; i < (ll)s.size(); ++i) {
        m[s[i] - 'a'].push_back(i+sLen);
    }

    auto f = [&](ll c, ll i, ll j) -> ll {
        if (m[c].empty()) return INF;
        ll iq = i / sLen;
        ll ir = i % sLen;
        ll mLen = (ll)m[c].size() / 2;
        ll jq = j / mLen;
        ll jr = j % mLen;
        if (jr == 0) {
            --jq;
            jr = mLen;
        }
        return *(lower_bound(m[c].begin(), m[c].end(), ir) + (jr - 1)) + (iq + jq) * sLen;
    };

    auto isOK = [&](ll x) -> bool {
        ll cur = -1;
        for (const char ch : t) {
            cur = f(ch - 'a', cur+1, x);
            if (cur >= n*sLen) return false;
        }
        return true;
    };

    ll ok = 0;
    ll ng = INF;
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;


    return 0;
}