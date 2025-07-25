#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <numeric>
#include <functional>
using namespace std;
using ll = long long;


template<
    class S = int,
    auto op = [](S v, S d) { return v + d; },
    auto inv_op = [](S u, S v) { return u - v; },
    auto e = []() { return 0; }
> class UnionFind {
    static_assert(is_convertible_v<decltype(op), function<S(S, S)>>);
    static_assert(is_convertible_v<decltype(inv_op), function<S(S, S)>>);
    static_assert(is_convertible_v<decltype(e), function<S()>>);

    vector<int> _parent;
    vector<S> _value;

public:
    UnionFind(int n) : _parent(n, -1), _value(n, e()) {}

    int get_root(int i) {
        stack<int> s;
        while (_parent[i] >= 0) {
            s.push(i);
            i = _parent[i];
        }
        S val = e();
        while (!s.empty()) {
            int j = s.top();
            s.pop();
            val = op(val, _value[j]);
            _value[j] = val;
            _parent[j] = i;
        }
        return i;
    }

    int get_size(int i) {
        return -_parent[get_root(i)];
    }

    int connect(int i, int j, S d) {
        int ri = get_root(i);
        int rj = get_root(j);
        if (ri == rj) {
            if (inv_op(_value[j], _value[i]) != d) return -1;
            return 0;
        }
        _parent[ri] += _parent[rj];
        _parent[rj] = ri;
        _value[rj] = inv_op(op(_value[i], d), _value[j]);
        return 1;
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    UnionFind<ll> uf(n);
    for (ll i = 0; i < m; ++i) {
        ll l, r, d;
        cin >> l >> r >> d;
        --l;
        --r;
        int result = uf.connect(l, r, d);
        if (result == -1) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}