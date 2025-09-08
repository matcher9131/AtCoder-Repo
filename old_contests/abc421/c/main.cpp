#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> a1(2*n);
    ll ai = 0, bi = 0;
    for (ll i = 0; i < 2*n; ++i) {
        if (s[i] == 'A') {
            a1[i] = 2 * ai;
            ++ai;
        } else {
            a1[i] = 2 * bi + 1;
            ++bi;
        }
    }
    atcoder::fenwick_tree<ll> fw1(2*n);
    ll ans1 = 0;
    for (ll i = 0; i < 2*n; ++i) {
        ans1 += fw1.sum(a1[i]+1, 2*n);
        fw1.add(a1[i], 1);
    }

    vector<ll> a2(2*n);
    ll ai2 = 0, bi2 = 0;
    for (ll i = 0; i < 2*n; ++i) {
        if (s[i] == 'A') {
            a2[i] = 2 * ai2 + 1;
            ++ai2;
        } else {
            a2[i] = 2 * bi2;
            ++bi2;
        }
    }
    atcoder::fenwick_tree<ll> fw2(2*n);
    ll ans2 = 0;
    for (ll i = 0; i < 2*n; ++i) {
        ans2 += fw2.sum(a2[i]+1, 2*n);
        fw2.add(a2[i], 1);
    }

    cout << min(ans1, ans2) << endl;

    return 0;
}