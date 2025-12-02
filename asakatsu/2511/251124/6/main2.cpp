#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

template<typename Query, typename Ans>
vector<Ans> mo(
    const vector<Query> &queries, 
    const ll m, 
    const function<void(ll)> &add_left, 
    const function<void(ll)> &add_right, 
    const function<void(ll)> &remove_left, 
    const function<void(ll)> &remove_right, 
    const function<Ans(Query)> &get_ans
) {
    ll nq = queries.size();
    vector<ll> order(nq);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](ll x, ll y) {
        if (queries[x].left / m < queries[y].left / m) return true;
        if (queries[x].left / m == queries[y].left / m && queries[x].right < queries[y].right) return true;
        return false;
    });

    vector<Ans> ans(nq);
    ll l = 0, r = 0;
    for (const ll i : order) {
        ll li = queries[i].left;
        ll ri = queries[i].right;
        while (l > li) add_left(--l);
        while (r < ri) add_right(r++);
        while (l < li) remove_left(l++);
        while (r > ri) remove_right(--r);
        ans[i] = get_ans(queries[i]);
    }
    return ans;
}

struct Query {
    ll left;
    ll right;
    ll d;
};

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (ll i = 1; i < n; ++i) {
        ll pi;
        cin >> pi;
        --pi;
        g[pi].push_back(i);
    }

    vector<ll> pre(n), post(n), depth(n);
    auto dfs = [&](auto dfs, ll from, ll d, ll &t) -> void {
        pre[from] = t++;
        depth[from] = d;
        for (const ll to : g[from]) {
            dfs(dfs, to, d+1, t);
        }
        post[from] = t++;
    };
    ll t = 0;
    dfs(dfs, 0, 0, t);

    vector<ll> td(2*n+1, n);
    for (ll i = 0; i < n; ++i) {
        td[post[i]] = depth[i];
    }

    ll nq;
    cin >> nq;
    vector<Query> q(nq);
    for (ll qi = 0; qi < nq; ++qi) {
        ll ui, di;
        cin >> ui >> di;
        --ui;
        q[qi] = { pre[ui], post[ui]+1, di };
    }

    ll m = sqrt(2*n);
    vector<ll> cd(n+1);
    auto add = [&](ll x) -> void {
        ++cd[td[x]];
    };
    auto remove = [&](ll x) -> void {
        --cd[td[x]];
    };
    auto getAns = [&](Query query) -> ll {
        return cd[query.d];
    };
    auto ans = mo<Query, ll>(q, m, add, add, remove, remove, getAns);
    for (ll qi = 0; qi < nq; ++qi) {
        cout << ans[qi] << endl;
    }

    return 0;
}