#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    string s;
    cin >> s;
    ll n = s.size();

    vector<ll> sum(n+1);
    for (ll i = 0; i < n; ++i) {
        sum[i+1] = sum[i] ^ (1LL << (s[i] - '0'));
    }

    unordered_map<ll, ll> m;
    for (const ll si : sum) {
        ++m[si];
    }

    ll ans = 0;
    for (const auto& [_, count] : m) {
        ans += count * (count-1) / 2;
    }

    cout << ans << endl;
    return 0;
}