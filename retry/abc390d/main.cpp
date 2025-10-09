#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_set<ll> ans;
    vector<ll> bag(n);
    auto dfs = [&](auto f, ll i, ll j) -> void {
        if (i == n) {
            ans.insert(accumulate(bag.begin(), bag.begin() + j, 0LL, [](ll acc, ll cur) { return acc ^ cur; }));
            return;
        }

        for (ll bi = 0; bi < j; ++bi) {
            bag[bi] += a[i];
            f(f, i+1, j);
            bag[bi] -= a[i];
        }
        bag[j] = a[i];
        f(f, i+1, j+1);
        bag[j] = 0;
    };
    dfs(dfs, 0, 0);

    cout << ans.size() << endl;

    return 0;
}