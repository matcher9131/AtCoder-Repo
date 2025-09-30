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

    ll ans = 0;
    ll right = n-1;
    while (!a.empty()) {
        ll x = a[right];
        if ((ll)a.size() < x+1) {
            cout << -1 << endl;
            return 0;
        }
        for (ll i = 0; i <= x; ++i) {
            if (a[right-i] < x-i) {
                cout << -1 << endl;
                return 0;
            }
            a[right-i] -= x-i;
            if (a[right-i] == 0) a.erase(a.begin() + right - i);
        }
        right = (ll)a.size() - 1;
        ans += x;

        // for (ll i = 0; i < (ll)a.size(); ++i) {
        //     cout << a[i] << " \n"[i == (ll)a.size() - 1];
        // }
    }

    cout << ans << endl;
    return 0;
}