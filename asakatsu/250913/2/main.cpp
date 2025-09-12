#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll a, b;
    cin >> a >> b;    

    ll ans = 0;
    while (a != b) {
        if (a < b) swap(a, b);
        if (a%b == 0) {
            ans += a/b - 1;
            break;
        } else {
            ans += a/b;
            a %= b;
        }
    }

    cout << ans << endl;
    return 0;
}