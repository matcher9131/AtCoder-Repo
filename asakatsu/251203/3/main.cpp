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
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }

    vector<ll> ans(n);
    for (ll i = 0; i < n; ++i) {
        bool canRemove = false;
        for (ll j = (ll)b.size() - 1; j >= 0; --j) {
            if (b[j] == j) {
                ans[i] = (j);
                b.erase(b.begin() + j);
                canRemove = true;
                break;
            }
        }
        if (!canRemove) {
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    for (ll i = 0; i < n; ++i) {
        cout << ans[i]+1 << endl;
    }

    return 0;
}