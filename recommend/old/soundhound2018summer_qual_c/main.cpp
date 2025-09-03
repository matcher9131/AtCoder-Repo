#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m, d;
    cin >> n >> m >> d;

    if (d > 0) {
        cout << setprecision(15) << (m-1) * 2 * (n-d) / (double)(n*n) << endl;
    } else {
        cout << setprecision(15) << (m-1) / (double)n << endl;
    }

    return 0;
}