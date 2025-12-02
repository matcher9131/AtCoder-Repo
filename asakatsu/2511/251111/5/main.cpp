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
    vector<ll> s(1e6+2);
    for (ll i = 0; i < n; ++i) {
        ll ai, bi;
        cin >> ai >> bi;
        ++bi;
        ++s[ai];
        --s[bi];
    }

    for (ll i = 1; i < (ll)s.size(); ++i) {
        s[i] += s[i-1];
    }

    cout << *max_element(s.begin(), s.end()) << endl;

    return 0;
}