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

    bool b = false;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'x') {
            cout << "No" << endl;
            return 0;
        } else if (s[i] == 'o') {
            b = true;
        }
    }

    cout << (b ? "Yes" : "No") << endl;
    return 0;
}