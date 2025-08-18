#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();

    vector<vector<ll>> tMap(26);
    for (ll j = 0; j < m; ++j) {
        tMap[t[j] - 'a'].push_back(j);
    }
    // 番兵
    for (ll ci = 0; ci < 26; ++ci) {
        tMap[ci].push_back(m);
    }
    
    vector<string> dp(m);
    for (ll i = 0; i < n; ++i) {
        ll c = s[i] - 'a';
        for (ll j = m-1; j >= 0; --j) {
            if (dp[j].empty()) {
                if (t[j] == s[i]) dp[j] = s[i];
            } else {
                ll nj = *lower_bound(tMap[c].begin(), tMap[c].end(), j+1);
                if (nj < m) {
                    string newVal = dp[j] + s[i];
                    if (newVal.size() > dp[nj].size()) dp[nj] = newVal;
                }
            }
        }
    }

    string ans = "";
    for (ll j = 0; j < m; ++j) {
        if (dp[j].size() > ans.size()) ans = dp[j];
    }
    cout << ans << endl;

    return 0;
}