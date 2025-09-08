#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, l, r;
    cin >> n >> l >> r;
    --l;
    --r;
    string s;
    cin >> s;

    for (ll i = l; i <= r; ++i) {
        if (s[i] != 'o') {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}