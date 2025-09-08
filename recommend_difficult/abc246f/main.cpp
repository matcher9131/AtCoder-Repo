#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, l;
    cin >> n >> l;
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    auto getNumDuplicated = [&](ull bit) -> ll {
        vector<bool> res(26, true);
        for (ll i = 0; i < n; ++i) {
            if (bit & (1ULL << i)) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    auto pos = s[i].find(c);
                    if (pos == string::npos) res[c - 'a'] = false;
                }
            }
        }
        return count(res.begin(), res.end(), true);
    };

    mint ans = 0;
    for (ull bit = 1; bit < (1ULL << n); ++bit) {
        ll numDuplicated = getNumDuplicated(bit);
        mint res = ((mint)numDuplicated).pow(l);
        if (popcount(bit) % 2 == 0) res = -res;
        ans += res;
    }

    cout << ans.val() << endl;
    return 0;
}