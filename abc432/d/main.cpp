#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n, x, y;
    cin >> n >> x >> y;

    // x1,x2,y1,y2 ※[x1, x2)
    vector<tuple<ll, ll, ll, ll>> rec;
    rec.emplace_back(0, x, 0, y);

    while (n--) {
        vector<tuple<ll, ll, ll, ll>> newRec;
        char c;
        ll a, b;
        cin >> c >> a >> b;
        if (c == 'X') {
            for (const auto &[x1, x2, y1, y2] : rec) {
                if (a <= x1) {
                    newRec.emplace_back(x1, x2, y1+b, y2+b);
                } else if (a >= x2) {
                    newRec.emplace_back(x1, x2, y1-b, y2-b);
                } else {
                    newRec.emplace_back(x1, a, y1-b, y2-b);
                    newRec.emplace_back(a, x2, y1+b, y2+b);
                }
            }
        } else {
            for (const auto &[x1, x2, y1, y2] : rec) {
                if (a <= y1) {
                    newRec.emplace_back(x1+b, x2+b, y1, y2);
                } else if (a >= y2) {
                    newRec.emplace_back(x1-b, x2-b, y1, y2);
                } else {
                    newRec.emplace_back(x1-b, x2-b, y1, a);
                    newRec.emplace_back(x1+b, x2+b, a, y2);
                }
            }
        }
        swap(rec, newRec);
    }

    ll m = rec.size();
    vector<ll> count(m);
    for (ll i = 0; i < m; ++i) {
        auto [x1,x2,y1,y2] = rec[i];
        count[i] = (x2-x1)*(y2-y1);
    }
    atcoder::dsu d(m);
    
    auto adjacent = [&](int i, int j) -> bool {
        auto [x1,x2,y1,y2] = rec[i];
        auto [x3,x4,y3,y4] = rec[j];
        if (x2 == x3 || x1 == x4) {
            return y3 < y2 && y1 < y4;
        } else if (y2 == y3 || y1 == y4) {
            return x3 < x2 && x1 < x4;
        }
        return false;
    };

    for (ll i = 0; i < m; ++i) {
        for (ll j = i+1; j < m; ++j) {
            if (adjacent(i, j)) {
                if (d.same(i, j)) continue;
                ll ci = count[d.leader(i)], cj = count[d.leader(j)];
                ll leader = d.merge(i, j);
                count[leader] = ci + cj;
            }
        }
    }

    vector<ll> ans;
    for (ll i = 0; i < m; ++i) {
        if (d.leader(i) == i) ans.push_back(count[i]);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}