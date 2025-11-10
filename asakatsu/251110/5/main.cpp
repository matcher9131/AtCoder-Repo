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
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
    }

    list<vector<ll>> rc(h, vector<ll>(26)), cc(w, vector<ll>(26));
    auto itr = rc.begin();
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            ++(*itr)[s[i][j] - 'a'];
            
        }
        ++itr;
    }
    auto itc = cc.begin();
    for (ll j = 0; j < w; ++j) {
        for (ll i = 0; i < h; ++i) {
            ++(*itc)[s[i][j] - 'a'];
        }
        ++itc;
    }

    auto getTarget = [](vector<ll> &v) -> ll {
        ll x = -1;
        ll count = 0;
        for (ll i = 0; i < (ll)v.size(); ++i) {
            if (v[i] >= 2) {
                x = i;
                ++count;
            } else if (v[i] > 0) {
                ++count;
            }
        }
        return count == 1 ? x : -1;
    };

    while (true) {
        vector<list<vector<ll>>::iterator> rt, ct;
        vector<ll> rd(26), cd(26);
        for (auto itr = rc.begin(); itr != rc.end(); ++itr) {
            ll res = getTarget(*itr);
            if (res != -1) {
                rt.push_back(itr);
                ++rd[res];
            }
        }
        for (auto itc = cc.begin(); itc != cc.end(); ++itc) {
            ll res = getTarget(*itc);
            if (res != -1) {
                ct.push_back(itc);
                ++cd[res];
            }
        }

        if (rt.empty() && ct.empty()) break;

        for (const auto &itr : rt) rc.erase(itr);
        for (const auto &itc : ct) cc.erase(itc);
        for (auto itr = rc.begin(); itr != rc.end(); ++itr) {
            for (ll i = 0; i < 26; ++i) {
                (*itr)[i] -= cd[i];
            }
        }
        for (auto itc = cc.begin(); itc != cc.end(); ++itc) {
            for (ll i = 0; i < 26; ++i) {
                (*itc)[i] -= rd[i];
            }
        }
    }

    ll ans = 0;
    for (auto itr = rc.begin(); itr != rc.end(); ++itr) {
        for (ll i = 0; i < 26; ++i) {
            ans += (*itr)[i];
        }
    }
    cout << ans << endl;

    return 0;
}