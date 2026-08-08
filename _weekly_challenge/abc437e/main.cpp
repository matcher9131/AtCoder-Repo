#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

struct Node {
    set<ll> tail;
    map<ll, Node*> children;
};

int main() {
    ll n;
    cin >> n;

    vector<Node*> nodes(n+1);
    nodes[0] = new Node();
    nodes[0]->tail.insert(0);

    for (ll i = 1; i <= n; ++i) {
        ll x, y;
        cin >> x >> y;

        if (nodes[x]->children.contains(y)) {
            nodes[i] = nodes[x]->children[y];
            nodes[i]->tail.insert(i);
        } else {
            Node* node = new Node();
            node->tail.insert(i);
            nodes[i] = node;
            nodes[x]->children[y] = node;
        }
    }

    vector<ll> ans;
    auto dfs = [&](auto dfs, Node* from) -> void {
        for (const ll i : from->tail) {
            ans.push_back(i);
        }
        for (const auto &[_, to] : from->children) {
            dfs(dfs, to);
        }
    };
    dfs(dfs, nodes[0]);

    for (ll i = 1; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}