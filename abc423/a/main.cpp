#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll x, c;
    cin >> x >> c;

    for (ll y = x/1000*1000; y >= 0; y -= 1000) {
        if (y + y/1000*c <= x) {
            cout << y << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}