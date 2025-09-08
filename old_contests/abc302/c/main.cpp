#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<vector<ll>> d(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        for (ll j = i+1; j < n; ++j) {
            ll count = 0;
            for (ll k = 0; k < m; ++k) {
                if (s[i][k] != s[j][k]) ++count;
            }
            d[i][j] = d[j][i] = count;
        }
    }

    vector<ll> perm(n);
    for (ll i = 0; i < n; ++i) {
        perm[i] = i;
    }
    do {
        ll i = 0;
        for (; i < n-1; ++i) {
            if (d[perm[i]][perm[i+1]] != 1) break;
        }
        if (i == n-1) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << "No" << endl;
    return 0;
}