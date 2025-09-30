#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> next(n);
    int right = 0;
    ll sum = 0;
    for (int left = 0; left < n; ++left) {
        while (right < n && sum + a[right] <= s) {
            sum += a[right];
            ++right;
        }

        next[left] = right;

        if (right == left) {
            ++right;
        } else {
            sum -= a[left];
        }
    }

    vector<ll> dp(n+1);
    for (ll i = n - 1; i >= 0; --i) {
        dp[i] = n - i + dp[next[i]];
    }

    cout << accumulate(dp.begin(), dp.end(), 0LL) << endl;

    return 0;
}