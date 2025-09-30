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

    vector<ll> chLv(26, -1);
    ll level = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '(') ++level;
        else if (s[i] == ')') {
            for (ll ci = 0; ci < 26; ++ci) {
                if (chLv[ci] == level) chLv[ci] = -1;
            }
            --level;
        } else {
            if (chLv[s[i] - 'a'] != -1) {
                cout << "No" << endl;
                return 0;
            }
            chLv[s[i] - 'a'] = level;
        }
    }

    cout << "Yes" << endl;
    return 0;
}