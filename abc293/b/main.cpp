#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    set<ll> notCalled;
    for (ll i = 0; i < n; ++i) {
        notCalled.insert(i);
    }

    for (ll i = 0; i < n; ++i) {
        if (notCalled.contains(i)) {
            notCalled.erase(a[i]);
        }
    }

    cout << notCalled.size() << endl;
    for (auto it = notCalled.begin(); it != notCalled.end(); ++it) {
        cout << *it + 1 << " \n"[it == notCalled.end()];
    }

    return 0;
}