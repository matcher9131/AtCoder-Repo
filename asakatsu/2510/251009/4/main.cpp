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
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    ll si = INF, sj = INF;
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == 'S') {
                si = i;
                sj = j;
            }
        }
    }

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<pair<ll, ll>> goal;
    for (const auto &[di, dj] : dir) {
        int ni = si + di, nj = sj + dj;
        if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] == '#') continue;
        goal.emplace_back(ni, nj);
    }

    for (ll i = 0; i < (ll)goal.size(); ++i) {
        ll ri = goal[i].first, rj = goal[i].second;
        set<pair<ll, ll>> other;
        for (ll j = 0; j < (ll)goal.size(); ++j) {
            if (i == j) continue;
            other.emplace(goal[j]);
        }

        vector<vector<ll>> dist(h, vector<ll>(w, INF));
        dist[ri][rj] = 0;
        queue<pair<ll, ll>> que;
        que.emplace(ri, rj);
        while (!que.empty()) {
            if (other.contains(que.front())) {
                cout << "Yes" << endl;
                return 0;
            }
            auto [i, j] = que.front();
            que.pop();
            for (const auto &[di, dj] : dir) {
                ll ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] != '.') continue;
                if (dist[ni][nj] < INF) continue;
                dist[ni][nj] = dist[i][j] + 1;
                que.emplace(ni, nj);
            }
        }
    }

    cout << "No" << endl;

    return 0;
}