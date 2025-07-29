#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

vector<ll> get_divisors(ll n) {
    vector<ll> res;
    for (ll d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            res.push_back(d);
            if (d != n / d) res.push_back(n/d);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> divisors = get_divisors(n);
    ll m = divisors.size();

    mint base2 = 2;
    vector<mint> ans(m);
    for (ll di = 0; di < m-1; ++di) {
        ll d = divisors[di];
        ll numNeed = 0;
        for (ll i = 0; i < d; ++i) {
            for (ll j = 0; j < n/d; ++j) {
                if (s[d*j+i] =='.') {
                    ++numNeed;
                    break;
                }
            }
        }
        ans[di] = base2.pow(d - numNeed);
        for (ll dj = 0; dj < di; ++dj) {
            if (divisors[di] % divisors[dj] == 0) ans[di] -= ans[dj];
        }
    }

    cout << accumulate(ans.begin(), ans.end(), (mint)0).val() << endl;

    return 0;
}