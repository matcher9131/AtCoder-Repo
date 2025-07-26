#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, k, x;
    cin >> n >> k >> x;
    --x;
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<string> ans;
    ll permMax = pow(n, k);
    for (ll i = 0; i < permMax; ++i) {
        ll j = i;
        string t;
        for (ll ki = 0; ki < k; ++ki) {
            t += s[j%n];
            j /= n;
        }
        ans.emplace_back(t);
    }
    sort(ans.begin(), ans.end());

    cout << ans[x] << endl;

    return 0;
}