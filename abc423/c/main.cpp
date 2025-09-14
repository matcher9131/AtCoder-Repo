#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, start;
    cin >> n >> start;
    vector<ll> a(n), s(n+1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }
    
    ll left = 0;
    for (; left < n; ++left) {
        if (!a[left]) break;
    }
    ++left;

    ll right = n-1;
    for (; right >= 0; --right) {
        if (!a[right]) break;
    }
    ++right;
    
    ll ans = (left <= start ? s[start] - s[left-1] + start - left + 1 : 0) + (start < right ? s[right] - s[start] + right - start : 0);
    cout << ans << endl;

    // printf("left = %lld, right = %lld\n", left, right);

    return 0;
}