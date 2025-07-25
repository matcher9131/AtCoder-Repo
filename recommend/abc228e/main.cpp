#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/math>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, k, m;
    cin >> n >> k >> m;
    if (m % 998244353 == 0) {
        cout << 0 << endl;
        return 0;
    }
    // r = k^n mod (p-1)
    ll r = atcoder::pow_mod(k, n, 998244352);
    cout << atcoder::pow_mod(m, r, 998244353) << endl;

    return 0;
}