#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll a, b;
    cin >> a >> b;

    cout << (a + b - 1) / b << endl;

    return 0;
}