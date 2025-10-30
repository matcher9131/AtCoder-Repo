#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    --a;
    --b;
    if (a > b) swap(a, b);
    
    if ((b-a) % 2 == 0) {
        cout << (b-a) / 2 << endl;
    } else {
        cout << min(a+1 + (b-a-1) / 2, n-b + (n-1-(a+n-b)) / 2) << endl;
    }

    return 0;
}