#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll a, b, x;
    cin >> a >> b >> x;

    cout << (a <= x && x <= a+b ? "YES" : "NO") << endl;

    return 0;
}