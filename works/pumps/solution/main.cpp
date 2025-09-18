#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll h, w, a, b;
    cin >> h >> w >> a >> b;
    
    bool flipped = h < w;
    if (flipped) swap(h, w);
    vector<vector<vector<ll>>> dp(h, vector<vector<ll>>(w, vector<ll>(1 << (w+1))));

    //

    return 0;
}