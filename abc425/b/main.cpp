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
    set<ll> unused;
    for (ll i = 0; i < n; ++i) {
        unused.insert(i);
    }
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        if (a[i] >= 0) {
            if (!unused.contains(a[i])) {
                cout << "No" << endl;
                return 0;
            }
            unused.erase(a[i]);
        }
    }

    for (ll i = 0; i < n; ++i) {
        if (a[i] < 0) {
            a[i] = *unused.begin();
            unused.erase(unused.begin());
        }
    }

    cout << "Yes" << endl;
    for (ll i = 0; i < (ll)a.size(); ++i) {
        cout << a[i]+1 << " \n"[i == (ll)a.size() - 1];
    }

    return 0;
}