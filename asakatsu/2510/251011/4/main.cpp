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
    string s;
    cin >> s;

    ll numL = 0;
    for (const char ch : s) {
        if (ch == '(') ++numL;
    }

    ll ans = 0;
    if (numL > n) {
        ll ex = numL - n;
        for (ll i = 2*n - 1; i >= 0; --i) {
            if (ex == 0) break;
            if (s[i] == '(') {
                s[i] = ')';
                ans += b;
                --ex;
            }
        }
    } else if (numL < n) {
        ll ex = n - numL;
        for (ll i = 0; i < 2*n; ++i) {
            if (ex == 0) break;
            if (s[i] == ')') {
                s[i] = '(';
                ans += b;
                --ex;
            }
        }
    }

    vector<ll> lv(2*n);
    lv[0] = s[0] == '(' ? 1 : -1;
    for (ll i = 1; i < 2*n; ++i) {
        lv[i] = lv[i-1] + (s[i] == '(' ? 1 : -1);
    }
    ll lvMin = *min_element(lv.begin(), lv.end());
    if (lvMin < 0) ans += (abs(lvMin) + 1) / 2 * min(a, 2*b);
    cout << ans << endl;

    return 0;
}