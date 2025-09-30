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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<map<ll, ll>> count(26);
    vector<map<ll, ll>> sum(26);
    vector<ll> ansSum(27);
    for (ll bi = 0; bi < 26; ++bi) {
        ll m = 1LL << bi;
        for (ll i = 0; i < n; ++i) {
            ll r = (-a[i] % m + m) % m;
            ++count[bi][r];
            sum[bi][r] += a[i];
            ansSum[bi] += count[bi][a[i] % m] * a[i] + sum[bi][a[i] % m];
        }
    }

    ll ans = 0;
    for (ll bi = 0; bi < 26; ++bi) {
        ans += (ansSum[bi] - ansSum[bi+1]) >> bi;
    }
    cout << ans << endl;

    return 0;
}