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
    vector<string> w(n);
    for (ll i = 0; i < n; ++i) {
        cin >> w[i];
    }

    unordered_set<string> s;
    s.insert(w[0]);
    char prev = w[0].back();
    for (ll i = 1; i < n; ++i) {
        if (s.contains(w[i]) || !w[i].starts_with(prev)) {
            cout << "No" << endl;
            return 0;
        }
        s.insert(w[i]);
        prev = w[i].back();
    }
    cout << "Yes" << endl;

    return 0;
}