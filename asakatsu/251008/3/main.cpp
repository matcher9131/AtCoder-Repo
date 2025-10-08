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
    string s;
    cin >> s;
    ll nq;
    cin >> nq;

    bool reversed = false;
    string pre, suf;

    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            reversed = !reversed;
        } else {
            ll f;
            char c;
            cin >> f >> c;
            if (f == 1) (reversed ? suf : pre) += c;
            else (reversed ? pre : suf) += c;
        }
    }

    reverse(pre.begin(), pre.end());
    string ans = pre + s + suf;
    if (reversed) reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}