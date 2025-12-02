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
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<pair<ll, ll>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    ll ansRed = ([&]() -> ll {
        vector<vector<ll>> dist(n, vector<ll>(n, INF));
        dist[0][0] = 0;
        priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
        que.emplace(0, 0, 0);
        while (!que.empty()) {
            auto [d, i, j] = que.top();
            que.pop();
            if (d > dist[i][j]) continue;
            for (const auto &[di, dj] : dir) {
                ll ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                ll cost = s[ni][nj] == 'B';
                if (dist[i][j] + cost < dist[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + cost;
                    que.emplace(dist[ni][nj], ni, nj);
                }
            }
        }
        return dist[n-1][n-1];
    })();

    ll ansBlue = ([&]() -> ll {
        vector<vector<ll>> dist(n, vector<ll>(n, INF));
        dist[0][n-1] = 0;
        priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
        que.emplace(0, 0, n-1);
        while (!que.empty()) {
            auto [d, i, j] = que.top();
            que.pop();
            if (d > dist[i][j]) continue;
            for (const auto &[di, dj] : dir) {
                ll ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                ll cost = s[ni][nj] == 'R';
                if (dist[i][j] + cost < dist[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + cost;
                    que.emplace(dist[ni][nj], ni, nj);
                }
            }
        }
        return dist[n-1][0];
    })();

    cout << ansRed + ansBlue << endl;

    return 0;
}