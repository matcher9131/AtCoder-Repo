#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    for (ll i = 0; i < n; ++i) {
        ll c;
        cin >> c;
        if (a+b == c) {
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}