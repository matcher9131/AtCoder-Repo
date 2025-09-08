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
    vector<ll> a(n), ca(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        ++ca[a[i]];
    }
    vector<ll> b(n), cb(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
        ++cb[b[i]];
    }

    bool dup = false;
    for (ll i = 0; i < n; ++i) {
        if (ca[i] != cb[i]) {
            cout << "No" << endl;
            return 0;
        }
        if (ca[i] >= 2) dup = true;
    }

    if (dup) {
        cout << "Yes" << endl;
        return 0;
    }

    atcoder::fenwick_tree<ll> fa(n+1), fb(n+1);
    ll ia = 0, ib = 0;
    for (ll i = 0; i < n; ++i) {
        ia += fa.sum(a[i]+1, n+1);
        ib += fb.sum(b[i]+1, n+1);
        fa.add(a[i], 1);
        fb.add(b[i], 1);
    }

    cout << (ia % 2 == ib % 2 ? "Yes" : "No") << endl;

    return 0;
}