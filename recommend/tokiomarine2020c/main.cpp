#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (ll ki = 0; ki < k; ++ki) {
        vector<ll> temp(n);
        for (ll i = 0; i < n; ++i) {
            ll left = i - a[i];
            ll right = i + a[i] + 1;
            ++temp[max(0LL, left)];
            if (right < n) --temp[right];
        }
        for (ll i = 0; i < n-1; ++i) {
            temp[i+1] += temp[i];
        }
        a = temp;
        if (all_of(a.begin(), a.end(), [&](ll val) { return val == n; })) break;
    }

    for (ll i = 0; i < (ll)a.size(); ++i) {
        cout << a[i] << " \n"[i == (ll)a.size() - 1];
    }
    return 0;
}