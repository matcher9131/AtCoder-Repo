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

    ll ans = 0;
    ll ansBit = 0;
    for (ull bit = 0; bit < 1ULL << h*w; ++bit) {
        ll sum = 0;
        for (ll i = 0; i < h; ++i) {
            for (ll j = 0; j < w; ++j) {
                if (bit & (1ULL << (i*w+j))) {
                    ll c = 0;
                    if (i < h-1 && (bit & (1ULL << ((i+1)*w+j))) == 0) ++c;
                    if (i < h-1 && j < w-1 && (bit & (1ULL << ((i+1)*w+j+1))) == 0) ++c;
                    if (i < h-1 && j > 0 && (bit & (1ULL << ((i+1)*w+j-1))) == 0) ++c;
                    if (i > 0 && (bit & (1ULL << ((i-1)*w+j))) == 0) ++c;
                    if (i > 0 && j < w-1 && (bit & (1ULL << ((i-1)*w+j+1))) == 0) ++c;
                    if (i > 0 && j > 0 && (bit & (1ULL << ((i-1)*w+j-1))) == 0) ++c;
                    if (j < w-1 && (bit & (1ULL << (i*w+j+1))) == 0) ++c; 
                    if (j > 0 && (bit & (1ULL << (i*w+j-1))) == 0) ++c; 
                    sum += a + c * b;
                }
            }
        }
        if (sum > ans) {
            ans = sum;
            ansBit = bit;
        }
    }

    cout << ans << endl;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cout << ((ansBit & (1ULL << (i*w+j))) ? '#' : '.');
        }
        cout << endl;
    }
}