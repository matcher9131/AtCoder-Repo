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

    ll t = 0, a = 0;
    bool tWins = true;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'T') ++t;
        else ++a;
        if (t>a) tWins = true;
        else if (t<a) tWins = false;
    }

    cout << (tWins ? "T" : "A") << endl;
    return 0;
}