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
    ll n;
    cin >> n;
    string r, c;
    cin >> r >> c;

    vector<string> g;
    auto colOk = [&](ll j, bool strict) -> bool {
        bool first = false;
        vector<ll> count(3);
        for (ll i = 0; i < (ll)g.size(); ++i) {
            if (g[i][j] == '.') continue;
            else if (!first && g[i][j] != c[j]) return false;
            else {
                first = true;
                ++count[g[i][j] - 'A'];
            }
        }
        return strict ? count[0] == 1 && count[1] == 1 && count[2] == 1
            : count[0] <= 1 && count[1] <= 1 && count[2] <= 1;
    };
    auto colsOk = [&](bool strict) -> bool {
        for (ll j = 0; j < n; ++j) {
            if (!colOk(j, strict)) return false;
        }
        return true;
    };

    auto rowOk = [&](string row, ll i) -> bool {
        for (ll j = 0; j < n; ++j) {
            if (row[j] == '.') continue;
            else if (row[j] == r[i]) return true;
            else return false;
        }
        return false;
    };

    auto dfs = [&](auto dfs) -> void {
        if ((ll)g.size() == n) {
            if (colsOk(true)) {
                cout << "Yes" << endl;
                for (ll i = 0; i < n; ++i) {
                    cout << g[i] << endl;
                }
                exit(0);
            }
            return;
        }

        string s(n-3, '.');
        s += "ABC";
        do {
            if (!rowOk(s, (ll)g.size())) continue;
            g.push_back(s);
            if (colsOk(false)) {
                dfs(dfs);
            }
            g.pop_back();
        } while (next_permutation(s.begin(), s.end()));
    };
    dfs(dfs);

    cout << "No" << endl;

    return 0;
}