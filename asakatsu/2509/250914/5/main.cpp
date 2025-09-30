#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    string s;
    cin >> s;
    ll n = s.size();
    ll gx, gy;
    cin >> gx >> gy;

    ll k = count(s.begin(), s.end(), 'T');

    ll m = 16001;
    vector<vector<vector<bool>>> dp(2, vector<vector<bool>>(k+1, vector<bool>(m)));
    ll t = s.find('T');
    if (t == (ll)string::npos) {
        cout << (gx == n && gy == 0 ? "Yes" : "No") << endl;
        return 0;
    }
    dp[0][0][t+8000] = true;
    dp[1][0][8000] = true;

    bool isY = true;
    ll ki = 1;
    while (true) {
        auto nt = s.find('T', t+1);
        if (nt == string::npos) nt = n;
        ll dif = nt - t - 1;
        for (ll i = 0; i < m; ++i) {
            if (dp[isY][ki-1][i]) {
                if (i+dif < m) dp[isY][ki][i+dif] = true;
                if (i-dif >= 0) dp[isY][ki][i-dif] = true;
            }
            dp[!isY][ki][i] = dp[!isY][ki-1][i];
        }
        t = nt;
        isY = !isY;
        ++ki;
        if ((ll)nt == n) break;
    }

    cout << (dp[0][k][gx+8000] && dp[1][k][gy+8000] ? "Yes" : "No") << endl;

    return 0;
}