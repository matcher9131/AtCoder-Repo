#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, nq;
    cin >> n >> nq;

    set<ll> notCalled;
    for (ll i = 0; i < n; ++i) {
        notCalled.insert(i);
    }
    set<ll> notDone;

    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            notDone.insert(*notCalled.begin());
            notCalled.erase(notCalled.begin());
        } else if (type == 2) {
            ll x;
            cin >> x;
            --x;
            notDone.erase(x);
        } else {
            cout << *notDone.begin() + 1 << endl;
        }
    }

    return 0;
}