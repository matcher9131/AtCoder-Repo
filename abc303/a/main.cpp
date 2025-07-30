#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    string s, t;
    cin >> n >> s >> t;

    for (ll i = 0; i < n; ++i) {
        if (s[i] == t[i] || (s[i] == '1' && t[i] == 'l') || (s[i] == 'l' && t[i] == '1') || (s[i] == '0' && t[i] == 'o') || (s[i] == 'o' && t[i] == '0')) continue;
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}