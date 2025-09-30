#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<string> ans(n, string(n, '_'));
    auto put = [&](ll i, ll x, ll y) -> void {
        ++i;
        if (i%4 == 0) ans[x][y] = s[x][y];
        else if (i%4 == 1) ans[y][n-1-x] = s[x][y];
        else if (i%4 == 2) ans[n-1-x][n-1-y] = s[x][y];
        else ans[n-1-y][x] = s[x][y];
    };

    for (ll i = 0; i < n/2; ++i) {
    
        {
            ll x = i;
            for (ll y = i; y < n-i; ++y) {
                put(i, x, y);
            }
        }
        {
            ll x = n-1-i;
            for (ll y = i; y < n-i; ++y) {
                put(i, x, y);
            }
        }
        for (ll x = i+1; x < n-1-i; ++x) {
            {
                ll y = i;
                put(i, x, y);
            }
            {
                ll y = n-1-i;
                put(i, x, y);
            }
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}