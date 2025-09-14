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

    vector<ll> ans{0};
    for (ll y = n; y > 0; y = (y - 1) & n) {
        ans.push_back(y);
    }
    sort(ans.begin(), ans.end());

    for (const ll x : ans) {
        cout << x << endl;
    }

    return 0;
}