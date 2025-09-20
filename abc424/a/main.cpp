#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    cout << (a == b || b == c || c == a ? "Yes" : "No") << endl;

    return 0;
}