#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    n %= a+b;
    cout << (0 < n && n <= a ? "Ant" : "Bug") << endl;

    return 0;
}