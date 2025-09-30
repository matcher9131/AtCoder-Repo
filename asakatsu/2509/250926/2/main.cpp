#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    mint ans = 1;
    for (ll i = 0; i < n; ++i) {
        if (a[i] - i <= 0) {
            cout << 0 << endl;
            return 0;
        }
        ans *= a[i] - i;
    }
    cout << ans.val() << endl;

    return 0;
}