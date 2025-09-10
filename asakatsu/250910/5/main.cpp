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
    vector<ll> s(n+1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }
    
    ll ans = (n-2)*(n-1)/2;
    for (ll i = 0; i < n; ++i) {
        ans += i * a[i];
    }

    ll current = ans;
    for (ll i = 2; i < n; i += 2) {
        current -= 2*(s[n] - s[i]);
        current += 2*(s[i-1] - s[0]);
        current -= n-i;
        current -= n-i-1;
        current += i-1;
        current += i-2;
        ans = min(ans, current);
    }

    cout << ans << endl;
    return 0;
}