#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    string a, b;
    cin >> a >> b;

    ll ans = -INF;
    {
        ll y = stoll(b);
        for (ll i = 1; i < 30; ++i) {
            string aa = a;
            if (i < 10) aa[0] = (char)(i + '0');
            else if (i < 20) aa[1] = (char)(i-10 + '0');
            else aa[2] = (char)(i-20 + '0');
            ll x = stoll(aa);
            ans = max(ans, x-y);
        }
    }
    
    {
        ll x = stoll(a);
        for (ll j = 1; j < 30; ++j) {
            string bb = b;
            if (j < 10) bb[0] = (char)(j + '0');
            else if (j < 20) bb[1] = (char)(j-10 + '0');
            else bb[2] = (char)(j-20 + '0');
            ll y = stoll(bb);
            ans = max(ans, x-y);
        }
    }

    cout << ans << endl;
    return 0;
}