#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<string> s(n);
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i] >> a[i];
    }
    ll si = min_element(a.begin(), a.end()) - a.begin();

    for (ll i = 0; i < n; ++i) {
        cout << s[(si + i) % n] << endl;
    }

    return 0;
}