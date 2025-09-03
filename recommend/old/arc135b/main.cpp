#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    // a[n+3] = s[n+1] - s[n] + a[n]
    vector<ll> b0{ 0 }, b1{ 0 }, b2{ 0 };
    for (ll i = 0; i+1 < n; i += 3) {
        b0.push_back(b0.back() + s[i+1] - s[i]);
    }
    for (ll i = 1; i+1 < n; i += 3) {
        b1.push_back(b1.back() + s[i+1] - s[i]);
    }
    for (ll i = 2; i+1 < n; i += 3) {
        b2.push_back(b2.back() + s[i+1] - s[i]);
    }
    ll a0 = -(*min_element(b0.begin(), b0.end()));
    ll a1 = -(*min_element(b1.begin(), b1.end()));
    ll a2 = -(*min_element(b2.begin(), b2.end()));
    if (a0 + a1 + a2 > s[0]) {
        cout << "No" << endl;
        return 0;
    }

    vector<ll> ans(n+2);
    ans[0] = a0;
    ans[1] = a1;
    ans[2] = s[0] - a0 - a1;
    for (ll i = 0; i+1 < n; ++i) {
        ans[i+3] = s[i+1] - s[i] + ans[i];
    }

    cout << "Yes" << endl;
    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }
    return 0;
}