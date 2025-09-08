#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(m, vector<ll>(n));
    for (ll i = 0; i < m; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> a[i][j];
            --a[i][j];
        }
    }

    vector<vector<bool>> ans(n, vector<bool>(n, true));
    for (ll i = 0; i < n; ++i) {
        ans[i][i] = false;
    }
    for (ll i = 0; i < m; ++i) {
        for (ll j = 0; j < n-1; ++j) {
            ans[a[i][j]][a[i][j+1]] = ans[a[i][j+1]][a[i][j]] = false;
        }
    }

    cout << accumulate(ans.begin(), ans.end(), 0LL, [](ll acc, vector<bool> &v) { return acc + count(v.begin(), v.end(), true); }) / 2 << endl;
    return 0;
}