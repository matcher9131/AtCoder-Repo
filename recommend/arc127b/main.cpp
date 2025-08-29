#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, l;
    cin >> n >> l;

    ll p3 = pow(3, l-1);

    auto toTernary = [&](ll x) -> string {
        string res;
        for (ll i = 0; i < l; ++i) {
            res += (char)(x % 3 + '0');
            x /= 3;
        }
        reverse(res.begin(), res.end());
        return res;
    };

    for (ll i = 0; i < n; ++i) {
        string s = toTernary(2 * p3 + i);
        cout << s << endl;
        string t = s;
        for (ll i = 0; i < l; ++i) {
            t[i] = (s[i] - '0' + 1) % 3 + '0';
        }
        cout << t << endl;
        string u = s;
        for (ll i = 0; i < l; ++i) {
            u[i] = (s[i] - '0' + 2) % 3 + '0';
        }
        cout << u << endl;
    }

    return 0;
}