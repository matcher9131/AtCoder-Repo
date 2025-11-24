#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Queryはleftとrightをメンバに持つこと

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