#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll a, n;
    cin >> a >> n;
    constexpr ll M = 1e6;

    vector<ll> dist(M+1, INF);
    dist[1] = 0;
    queue<ll> que;
    que.push(1);
    while (!que.empty()) {
        ll x = que.front();
        que.pop();
        if (a*x < M && dist[a*x] == INF) {
            dist[a*x] = dist[x] + 1;
            que.push(a*x);
        }
        if (x >= 10 && x%10 > 0) {
            string s = to_string(x);
            ll y = stoll(s.substr(s.size() - 1) + s.substr(0, s.size() - 1));
            if (dist[y] == INF) {
                dist[y] = dist[x] + 1;
                que.push(y);
            }
        }
    }

    cout << (dist[n] == INF ? -1 : dist[n]) << endl;

    return 0;
}