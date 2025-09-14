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
    vector<ll> l(n);
    for (ll i = 0; i < n; ++i) {
        cin >> l[i];
    }

    ll left = 0;
    for (; left < n; ++left) {
        if (l[left]) break;
    }

    ll right = n-1;
    for (; right >= 0; --right) {
        if (l[right]) break;
    }

    cout << max(right - left, 0LL) << endl;

    return 0;
}