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
    string t;
    cin >> t;
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    ll nt = t.size();
    vector<ll> ans;
    for (ll i = 0; i < n; ++i) {
        ll ns = s[i].size();
        if (ns == nt) {
            ll c = 0;
            for (ll j = 0; j < ns; ++j) {
                if (s[i][j] != t[j]) ++c;
            }
            if (c <= 1) ans.push_back(i);
        } else if (ns == nt+1 || ns == nt-1) {
            ll l = 0, r = 0;
            ll mj = min(ns, nt);
            for (ll j = 0; j < mj; ++j) {
                if (s[i][j] == t[j]) ++l;
                else break;
            }
            for (ll j = 0; j < mj; ++j) {
                if (s[i][ns-1-j] == t[nt-1-j]) ++r;
                else break;
            }
            if (l+r >= mj) ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i]+1 << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}