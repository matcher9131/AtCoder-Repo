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
    vector<ll> ans;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        ans.push_back(ai);
        for (ll j = (ll)ans.size() - 2; j >= 0; --j) {
            if (ans[j] == ans[j+1]) {
                ans.erase(ans.end() - 1);
                ++ans[j];
            } else {
                break;
            }
        }
    }

    cout << ans.size() << endl;

    return 0;
}