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
    ll n;
    cin >> n;

    ll k = (ll)sqrt(2*n);
    if (2*n != k * (k+1)) {
        cout << "No" << endl;
        return 0;
    }

    vector<vector<ll>> ans(k+1, vector<ll>(k));
    ll next = -1;
    for (ll i = 0; i < k+1; ++i) {
        ll j = 0;
        for (; j < i; ++j) {
            ans[i][j] = ans[j][i-1];
        }
        for (; j < k; ++j) {
            ans[i][j] = ++next;
        }
    }

    cout << "Yes" << endl;
    cout << k+1 << endl;
    for (ll i = 0; i < k+1; ++i) {
        cout << k << " ";
        for (ll j = 0; j < (ll)ans[i].size(); ++j) {
            cout << ans[i][j]+1 << " \n"[j == (ll)ans[i].size() - 1];
        }
    }

    return 0;
}