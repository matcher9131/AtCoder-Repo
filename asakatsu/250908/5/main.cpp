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
    vector<ll> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    vector<ll> a(n+2);
    a[2] = s[0];
    for (ll i = 3; i < n+2; ++i) {
        a[i] = s[i-2] - s[i-3] + a[i-3];
    }

    ll a0min = 0;
    for (ll i = 0; 3*i < n+2; ++i) {
        chmax(a0min, -a[3*i]);
    }
    ll a1min = 0;
    for (ll i = 0; 3*i+1 < n+2; ++i) {
        chmax(a1min, -a[3*i+1]);
    }
    ll a2min = INF;
    for (ll i = 0; 3*i+2 < n+2; ++i) {
        chmin(a2min, a[3*i+2]);
    }
    if (a2min - a0min - a1min < 0) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    for (ll i = 0; i < n+2; ++i) {
        if (i%3 == 0) a[i] += a0min;
        else if (i%3 == 1) a[i] += a1min;
        else a[i] -= a0min + a1min;
    }
    for (ll i = 0; i < (ll)a.size(); ++i) {
        cout << a[i] << " \n"[i == (ll)a.size() - 1];
    }

    return 0;
}