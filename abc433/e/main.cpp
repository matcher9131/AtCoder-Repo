#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

void solve() {
    ll h, w;
    cin >> h >> w;
    vector<ll> x(h);
    for (ll i = 0; i < h; ++i) {
        cin >> x[i];
        --x[i];
    }
    vector<ll> y(w);
    for (ll j = 0; j < w; ++j) {
        cin >> y[j];
        --y[j];
    }

    vector<pair<ll, ll>> shouldBe(h*w, {-1, -1});
    for (ll i = 0; i < h; ++i) {
        if (shouldBe[x[i]].first != -1) {
            cout << "No" << endl;
            return;
        }
        shouldBe[x[i]].first = i;
    }
    for (ll j = 0; j < w; ++j) {
        if (shouldBe[y[j]].second != -1) {
            cout << "No" << endl;
            return;
        }
        shouldBe[y[j]].second = j;
    }

    vector<vector<ll>> ans(h, vector<ll>(w, -1));
    set<ll> cr, cc;
    vector<set<ll>> tRow(h), tCol(w);
    set<pair<ll, ll>> tCell;

    auto eraseTarget = [&](ll i, ll j) -> void {
        tRow[i].erase(j);
        tCol[j].erase(i);
        tCell.erase({i, j});
    };

    for (ll k = h*w - 1; k >= 0; --k) {
        auto [i, j] = shouldBe[k];
        if (i != -1 && j != -1) {
            ans[i][j] = k;
            for (const ll jj : cc) {
                if (ans[i][jj] == -1) tCell.emplace(i, jj);
            }
            for (const ll ii : cr) {
                if (ans[ii][j] == -1) tCell.emplace(ii, j);
            }
            cr.insert(i);
            cc.insert(j);
            for (ll ii = 0; ii < h; ++ii) {
                if (ans[ii][j] == -1) tRow[ii].insert(j);
            }
            for (ll jj = 0; jj < w; ++jj) {
                if (ans[i][jj] == -1) tCol[jj].insert(i);
            }
            eraseTarget(i, j);
        } else if (i != -1) {
            if (tRow[i].empty()) {
                cout << "No" << endl;
                return;
            }
            ll j = *tRow[i].begin();
            ans[i][j] = k;
            for (const ll jj : cc) {
                if (ans[i][jj] == -1) tCell.emplace(i, jj);
            }
            cr.insert(i);
            for (ll jj = 0; jj < w; ++jj) {
                if (ans[i][jj] == -1) tCol[jj].insert(i);
            }
            eraseTarget(i, j);
        } else if (j != -1) {
            if (tCol[j].empty()) {
                cout << "No" << endl;
                return;
            }
            ll i = *tCol[j].begin();
            ans[i][j] = k;
            for (const ll ii : cr) {
                if (ans[ii][j] == -1) tCell.emplace(ii, j);
            }
            cc.insert(j);
            for (ll ii = 0; ii < h; ++ii) {
                if (ans[ii][j] == -1) tRow[ii].insert(j);
            }
            eraseTarget(i, j);
        } else {
            if (tCell.empty()) {
                cout << "No" << endl;
                return;
            }
            auto [i, j] = *tCell.begin();
            ans[i][j] = k;
            eraseTarget(i, j);
        }
    }
    
    cout << "Yes" << endl;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < (ll)ans[i].size(); ++j) {
            cout << ans[i][j]+1 << " \n"[j == (ll)ans[i].size() - 1];
        }
    }
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}