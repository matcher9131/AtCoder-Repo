#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll x, y, k;
    cin >> x >> y >> k;

    if (y < k) {
        k -= y;
        x += y;
        y = 0;
        cout << x-k << endl;
    } else {
        cout << x+k << endl;
    }

    return 0;
}