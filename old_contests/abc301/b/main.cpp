#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> ans{ a[0] };
    for (ll i = 1; i < n; ++i) {
        ll prev = ans.back();
        if (prev < a[i]) {
            for (ll x = prev + 1; x <= a[i]; ++x) {
                ans.push_back(x);
            }
        } else {
            for (ll x = prev - 1; x >= a[i]; --x) {
                ans.push_back(x);
            }
        }
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }
    return 0;
}