#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    string ss, sg;
    cin >> ss >> sg;
    ll n;
    cin >> n;
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }
    s.push_back(ss);
    s.push_back(sg);
    ll m = ss.size();
    n = s.size();

    if (ss == sg) {
        cout << 0 << endl;
        cout << ss << endl;
        cout << sg << endl;
        return 0;
    }

    auto isOK = [&](string &s1, string &s2) -> bool {
        ll count = 0;
        for (ll k = 0; k < m; ++k) {
            if (s1[k] != s2[k]) ++count;
        }
        return count == 1;
    };

    vector<vector<ll>> g(n);
    for (ll i = 0; i < n; ++i) {
        for (ll j = i+1; j < n; ++j) {
            if (isOK(s[i], s[j])) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    vector<ll> dist(n, INF);
    vector<ll> last(n, -1);
    dist[n-2] = 0;
    queue<ll> que;
    que.push(n-2);
    while (!que.empty()) {
        ll v = que.front();
        que.pop();
        for (const ll nv : g[v]) {
            if (dist[nv] < INF) continue;
            dist[nv] = dist[v] + 1;
            last[nv] = v;
            que.push(nv);
        }
    }

    if (dist[n-1] == INF) {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> buf;
    buf.reserve(dist[n-1]);
    ll current = n-1;
    while (current > -1) {
        buf.push_back(current);
        current = last[current];
    }
    reverse(buf.begin(), buf.end());

    cout << dist[n-1] - 1 << endl;
    for (const ll i : buf) {
        cout << s[i] << endl;
    }

    return 0;
}