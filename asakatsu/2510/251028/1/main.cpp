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
    ll a = -1, b = -1, c = -1, d = -1;
    for (ll i = 0; i < 10; ++i) {
        string si;
        cin >> si;
        si += '.';
        auto j = si.find('#');
        if (j != string::npos) {
            if (a == -1) {
                a = i;
                c = j;
                d = si.find('.', j);
            }
        } else {
            if (b == -1 && a != -1) b = i;
        }
    }
    if (b == -1) b = 10;

    cout << a+1 << " " << b << endl;
    cout << c+1 << " " << d << endl;

    return 0;
}