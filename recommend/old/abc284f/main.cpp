#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/math>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

constexpr ll B = 99971;
vector<ll> mod{ 998244353, 1000000007, 1000000087 };
ll mod_size = mod.size();

int main() {
    ll n;
    string t;
    cin >> n >> t;

    vector<ll> hl(mod_size), hr(mod.size());
    // 初期化
    for (ll j = 0; j < mod_size; ++j) {
        for (ll i = 0; i < n; ++i) {
            hl[j] *= B;
            hl[j] += t[i] - 'a';
            hl[j] %= mod[j];
            hr[j] *= B;
            hr[j] += t[2*n-1-i] - 'a';
            hr[j] %= mod[j];
        }
    }

    auto matches = [&]() -> bool {
        for (ll j = 0; j < mod_size; ++j) {
            if (hl[j] != hr[j]) return false;
        }
        return true;
    };

    for (ll i = 0; i < n; ++i) {
        if (matches()) {
            string ans = t.substr(i, n);
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
            cout << i << endl;
            return 0;
        }
        for (ll j = 0; j < mod_size; ++j) {
            hl[j] -= ((t[i] - 'a') * atcoder::pow_mod(B, n-1, mod[j]) % mod[j]);
            hl[j] += mod[j];
            hl[j] *= B;
            hl[j] += t[i+n] - 'a';
            hl[j] %= mod[j];

            hr[j] -= ((t[i+n] - 'a') * atcoder::pow_mod(B, i, mod[j]) % mod[j]);
            hr[j] += mod[j];
            hr[j] += (t[i] - 'a') * atcoder::pow_mod(B, i, mod[j]);
            hr[j] %= mod[j];
        }
    }

    cout << -1 << endl;
    return 0;
}