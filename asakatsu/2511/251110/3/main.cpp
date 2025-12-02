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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    stack<pair<ll, ll>> st;
    for (const ll x : a) {
        ++ans;
        if (st.empty()) {
            st.emplace(x, 1);
        } else {
            auto [v, c] = st.top();
            if (x == v) {
                st.pop();
                ++c;
                if (c < x) {
                    st.emplace(v, c);
                } else {
                    ans -= v;
                }
            } else {
                st.emplace(x, 1);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}