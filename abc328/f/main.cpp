#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;


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
    ll n, nq;
    cin >> n >> nq;
    UnionFind<ll> uf(n);

    vector<int> ans;
    for (ll qi = 0; qi < nq; ++qi) {
        ll a, b, d;
        cin >> a >> b >> d;
        --a;
        --b;
        // b + d = a
        int result = uf.connect(b, a, d);
        if (result != -1) ans.push_back(qi);
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i]+1 << " \n"[i == (ll)ans.size() - 1];
    }
    return 0;
}