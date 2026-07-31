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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<>());

    set<vector<ll>> visited;
    vector<ll> s0(n+1);
    s0[1] = k;
    s0[0] = k * a[0];
    priority_queue<vector<ll>> que;
    que.push(s0);  

    for (ll xi = 0; xi < x; ++xi) {
        vector<ll> si = que.top();
        que.pop();

        cout << si[0] << "\n";

        for (ll j = 1; j < n; ++j) {
            if (si[j] == 0) continue;
            vector<ll> ns = si;
            --ns[j];
            ++ns[j+1];
            ns[0] = inner_product(a.begin(), a.end(), ns.begin()+1, 0LL);
            if (visited.contains(ns)) continue;
            que.push(ns);
            visited.insert(ns);
        }
    }

    return 0;
}