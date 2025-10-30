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
    ll n;
    cin >> n;
    ll n1 = 0, n2 = 0, n4 = 0;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        if (ai % 4 == 0) ++n4;
        else if (ai % 4 == 2) ++n2;
        else ++n1;
    }

    ll prev = 4;
    for (ll i = 0; i < n; ++i) {
        if (prev == 1) {
            if (n4 > 0) --n4, prev = 4;
            else {
                cout << "No" << endl;
                return 0;
            }
        } else if (prev == 2) {
            if (n2 > 0) --n2, prev = 2;
            else if (n4 > 0) --n4, prev = 4;
            else {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (n1 > 0) --n1, prev = 1;
            else if (n2 > 0) --n2, prev = 2;
            else --n4, prev = 4;
        }
    }
    cout << "Yes" << endl;

    return 0;
}