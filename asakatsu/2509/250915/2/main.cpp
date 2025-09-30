#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n-1);
    for (ll i = 0; i < n-1; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    for (ll y = 0; y <= 100; ++y) {
        vector<ll> b = a;
        b.push_back(y);
        sort(b.begin(), b.end());
        if (accumulate(b.begin()+1, b.end()-1, 0LL) >= x) {
            cout << y << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}