#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18+1;
using i128 = __int128_t;

inline i128 getMax(set<pair<i128, ll>> &s) {
    return s.empty() ? 0 : s.rbegin()->first;
};

int main() {
    ll n, _h;
    cin >> n >> _h;
    i128 h = _h;
    vector<i128> t(n), d(n);
    for (ll i = 0; i < n; ++i) {
        ll ti, di;
        cin >> ti >> di;
        t[i] = ti;
        d[i] = di;
    }

    // key: tとして現れる数字, value: dが最大になる魔法のインデックス
    map<i128, ll> border;
    border[0] = -1;
    border[INF] = -1;
    for (ll i = 0; i < n; ++i) {
        if (border.contains(t[i]) && border[t[i]] != -1) {
            if (d[i] > d[border[t[i]]]) border[t[i]] = i;
        } else {
            border[t[i]] = i;
        }
    }

    // di, i
    set<pair<i128, ll>> setNotFull;
    // ti*di, i
    set<pair<i128, ll>> setFull;
    vector<set<pair<i128, ll>>::iterator> itMap(n);
    for (const auto &[ti, i] : border) {
        if (i == -1) continue;
        auto [it, _] = setNotFull.emplace(d[i], i);
        itMap[i] = it;
    }

    for (auto borderIt = border.begin(); borderIt != border.end(); ++borderIt) {
        auto [tLeft, i] = *borderIt;
        if (tLeft == INF) break;
        auto borderNext = borderIt;
        ++borderNext;
        i128 tRight = borderNext->first;
        if (i >= 0) {
            setNotFull.erase(itMap[i]);
            setFull.emplace(t[i] * d[i], i);
        }

        i128 t0 = max(min(tRight, getMax(setNotFull) == 0 ? tRight : getMax(setFull) / getMax(setNotFull)), tLeft);
        i128 damage = (t0 - tLeft) * getMax(setFull) + (tRight + t0 + 1) * (tRight - t0) / 2 * getMax(setNotFull);
        if (damage >= h) {
            i128 ok = tRight;
            i128 ng = tLeft;
            while (ok - ng > 1) {
                i128 mid = (ok + ng) / 2;
                i128 damage2 = (min(mid, t0) - tLeft) * getMax(setFull) + (mid + t0 + 1) * max(mid - t0, (i128)0) / 2 * getMax(setNotFull);
                if (damage2 >= h) ok = mid;
                else ng = mid;
            }
            cout << (ll)ok << endl;
            return 0;
        } else {
            h -= damage;
        }
    }
    
    return 0;
}