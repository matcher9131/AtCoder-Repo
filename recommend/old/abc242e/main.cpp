#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    mint ans = 0;
    for (ll i = 0; i < (n+1)/2; ++i) {
        ans *= 26;
        ans += s[i] - 'A';
    }

    string t = s;
    for (ll i = 0; i < n/2; ++i) {
        t[n-1-i] = t[i];
    }
    if (t <= s) ++ans;

    cout << ans.val() << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}