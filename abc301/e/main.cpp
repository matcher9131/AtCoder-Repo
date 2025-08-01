#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll h, w, t;
    cin >> h >> w >> t;
    vector<string> s(h);
    // type, i, j
    vector<tuple<ll, ll, ll>> cell;
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == 'S') cell.emplace_back(0, i, j);
            else if (s[i][j] == 'o') cell.emplace_back(1, i, j);
            else if (s[i][j] == 'G') cell.emplace_back(2, i, j);
        }
    }
    ll n = cell.size();
    sort(cell.begin(), cell.end());

    vector<pair<ll, ll>> dir{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    vector<vector<ll>> cellDist(n, vector<ll>(n, INF));
    for (ll ci = 0; ci < n; ++ci) {
        auto [_, si, sj] = cell[ci];
        vector<vector<ll>> dist(h, vector<ll>(w, INF));
        dist[si][sj] = 0;
        queue<pair<ll, ll>> que;
        que.emplace(si, sj);
        while (!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            for (const auto &[di, dj] : dir) {
                ll ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] == '#') continue;
                if (dist[ni][nj] < INF) continue;
                dist[ni][nj] = dist[i][j] + 1;
                que.emplace(ni, nj);
            }
        }
        
        for (ll cj = 0; cj < n; ++cj) {
            auto [__, gi, gj] = cell[cj];
            cellDist[ci][cj] = dist[gi][gj];
        }
    }

    if (cellDist[0][n-1] > t) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<ll>> dp(1LL << n, vector<ll>(n, INF));
    dp[1][0] = 0;
    for (ll bit = 1; bit < 1LL << n; ++bit) {
        for (ll i = 0; i < n; ++i) {
            if (dp[bit][i] == INF) continue;
            for (ll j = 0; j < n; ++j) {
                if (i == j) continue;
                if (bit & (1LL << j)) continue;
                ll newBit = bit | (1LL << j);
                dp[newBit][j] = min(dp[newBit][j], dp[bit][i] + cellDist[i][j]);
            }
        }
    }

    int ans = 0;
    for (ull bit = (1ULL << (n-1)) + 1; bit < 1ULL << n; bit += 2) {
        if (dp[bit][n-1] <= t) ans = max(ans, popcount(bit) - 2);
    }

    cout << ans << endl;

    return 0;
}