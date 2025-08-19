#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> visited(n);
    vector<mint> white(n), black(n);
    function<void(ll, ll)> dfs = [&](ll from, ll parent) -> void {
        visited[from] = true;
        for (const ll to : g[from]) {
            if (to == parent) continue;
            dfs(to, from);
        }
        // 帰りがけ
        mint w = 1, b = 1;
        for (const ll to : g[from]) {
            if (to == parent) continue;
            w *= white[to] + black[to];
            b *= white[to];
        }
        white[from] = w;
        black[from] = b;
    };
    dfs(0, -1);

    cout << (white[0] + black[0]).val() << endl;

    return 0;
}