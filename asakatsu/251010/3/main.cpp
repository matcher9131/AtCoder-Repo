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
    vector<string> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_set<string> used;
    used.insert(a[0]);
    char prev = a[0].back();
    for (ll i = 1; i < n; ++i) {
        if (used.contains(a[i]) || a[i][0] != prev) {
            cout << (i%2 ? "WIN" : "LOSE") << endl;
            return 0;
        }
        used.insert(a[i]);
        prev = a[i].back();
    }

    cout << "DRAW" << endl;

    return 0;
}