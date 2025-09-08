#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, nq;
    cin >> n >> nq;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    vector<ll> s(n+1);
    for (ll i = 0; i < n; ++i) {
        s[i+1] = s[i] + a[i];
    }

    while (nq--) {
        ll bi;
        cin >> bi;
        if (bi > a[n-1]) {
            cout << -1 << endl;
            continue;
        }
        int i = upper_bound(a.begin(), a.end(), bi-1) - a.begin();
        cout << s[i] + (bi-1) * (n-i) + 1 << endl;
    }

    return 0;
}