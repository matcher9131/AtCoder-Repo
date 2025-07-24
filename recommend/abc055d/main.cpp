#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    string s;
    cin >> n >> s;

    vector<string> ans(4, string(n, '_'));
    ans[0][0] = 'S'; ans[0][1] = 'S';
    ans[1][0] = 'S'; ans[1][1] = 'W';
    ans[2][0] = 'W'; ans[2][1] = 'S';
    ans[3][0] = 'W'; ans[3][1] = 'W';

    for (ll i = 1; i < n-1; ++i) {
        for (ll j = 0; j < 4; ++j) {
            if (ans[j][i-1] == ans[j][i]) {
                ans[j][i+1] = s[i] == 'o' ? 'S' : 'W';
            } else {
                ans[j][i+1] = s[i] == 'o' ? 'W' : 'S';
            }
        }
    }

    auto contradict = [](char reply, string represent) -> bool {
        return (reply == 'o') ^ (represent == "SSS" || represent == "WSW" || represent == "SWW" || represent == "WWS");
    };

    for (ll j = 0; j < 4; ++j) {
        if (!contradict(s[n-1], ans[j].substr(n-2) + ans[j][0]) && !contradict(s[0], ans[j][n-1] + ans[j].substr(0, 2))) {
            cout << ans[j] << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}