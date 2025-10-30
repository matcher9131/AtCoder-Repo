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
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    --a;
    --b;
    --c;
    --d;
    string s;
    cin >> s;

    auto hasSuccessiveRock = [&](ll from, ll to) -> bool {
        bool isRock = false;
        for (ll i = from; i <= to; ++i) {
            if (s[i] == '#') {
                if (isRock) return true;
                else isRock = true;
            } else {
                isRock = false;
            }
        }
        return false;
    };

    auto hasSuccessiveBlank = [&](ll from, ll to) -> bool {
        for (ll i = from; i <= to-2; ++i) {
            if (s[i] == '.' && s[i+1] == '.' && s[i+2] == '.') return true;
        }
        return false;
    };

    if (hasSuccessiveRock(a,c) || hasSuccessiveRock(b,d)) {
        cout << "No" << endl;
        return 0;
    }

    if (c > d) {
        if (!hasSuccessiveBlank(max(0LL, b-1), min(n, d+1))) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}