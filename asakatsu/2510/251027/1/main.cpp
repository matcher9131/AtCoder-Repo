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
    ll a, b, k;
    cin >> a >> b >> k;

    ll kth = 0;
    for (ll i = min(a,b); i >= 1; --i) {
        if (a%i == 0 && b%i == 0) {
            ++kth;
            if (kth == k) {
                cout << i << endl;
                return 0;
            }
        }
    }

    return 0;
}