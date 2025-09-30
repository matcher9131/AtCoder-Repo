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
    unordered_map<string, ll> m;
    for (ll i = 0; i < n; ++i) {
        string si;
        cin >> si;
        ++m[si];
    }

    ll maxCount = 0;
    string ans;
    for (const auto &[s, c] : m) {
        if (c > maxCount) {
            maxCount = c;
            ans = s;
        }
    }

    cout << ans << endl;
    return 0;
}