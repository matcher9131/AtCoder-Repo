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
    ll h, w;
    cin >> h >> w;
    cout << string(w+2, '#') << endl;
    for (ll i = 0; i < h; ++i) {
        cout << "#";
        string s;
        cin >> s;
        cout << s;
        cout << "#" << endl;
    }
    cout << string(w+2, '#') << endl;

    return 0;
}