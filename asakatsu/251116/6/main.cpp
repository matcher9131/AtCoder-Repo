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
    ll k, n;
    cin >> k >> n;
    vector<string> v(n), w(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i] >> w[i];
    }

    auto getAns = [&](vector<ll> &len) -> vector<string> {
        vector<string> res(k);
        for (ll i = 0; i < n; ++i) {
            ll left = 0;
            ll wLen = w[i].size();
            for (const char c : v[i]) {
                ll x = c - '1';
                if (wLen - left < len[x]) return vector<string>();
                string t = w[i].substr(left, len[x]);
                if (res[x] == "") res[x] = t;
                else if (res[x] != t) return vector<string>();
                left += len[x];
            }
            if (left < wLen) return vector<string>();
        }
        return res;
    };

    for (ll pattern = 0; pattern < pow(3, k); ++pattern) {
        vector<ll> len(k);
        ll x = pattern;
        for (ll i = 0; i < k; ++i) {
            len[i] = x%3 + 1;
            x /= 3;
        }

        vector<string> ans = getAns(len);
        if (!ans.empty()) {
            for (const string &ai : ans) cout << ai << endl;
            return 0;
        }
    }

    return 0;
}