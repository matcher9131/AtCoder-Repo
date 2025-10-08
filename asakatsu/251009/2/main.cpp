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
    priority_queue<ll> a, b;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        a.push(ai);
    }
    for (ll i = 0; i < n-1; ++i) {
        ll bi;
        cin >> bi;
        b.push(bi);
    }

    ll ans = INF;
    while (!b.empty()) {
        ll ai = a.top();
        ll bi = b.top();
        if (ai > bi) {
            if (ans != INF) {
                cout << -1 << endl;
                return 0;
            } else {
                ans = ai;
                a.pop();
            }
        } else {
            a.pop();
            b.pop();
        }
    }
    if (!a.empty()) ans = a.top();
    
    cout << ans << endl;

    return 0;
}