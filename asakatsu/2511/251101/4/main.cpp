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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> one, zero;
    if (s[0] == '0') one.push_back(0);
    ll left = 0;
    while (left < n) {
        ll right = left;
        while (right < n && s[right] == s[left]) ++right;
        (s[left] == '0' ? zero : one).push_back(right - left);
        left = right;
    }
    if (s[n-1] == '0') one.push_back(0);

    ll m = zero.size();
    if (m <= k) {
        cout << n << endl;
        return 0;
    }

    ll ans = 0;
    for (ll i = 0; i < m-k+1; ++i) {
        ll sum = 0;
        for (ll j = 0; j < k; ++j) {
            sum += one[i+j] + zero[i+j];
        }
        sum += one[i+k];
        chmax(ans, sum);
    }
    cout << ans << endl;

    return 0;
}