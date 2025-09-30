#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    auto isValid = [&](ll i, ll j) -> bool {
        return !(i < 0 || i >= n || j < 0 || j >= n || s[i][j] == '#');
    };

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    auto isNextToRed = [&](ll i, ll j) -> bool {
        for (const auto &[di, dj] : dir) {
            int ni = i + di, nj = j + dj;
            if (isValid(ni, nj) && s[ni][nj] == '@') return true;
        }
        return false;
    };

    ll ans = 0;
    set<vector<string>> checked;
    function<void(ll)> dfs = [&](ll rest) -> void {
        if (checked.contains(s)) return;
        checked.insert(s);
        if (rest == 0) {
            ++ans;
            return;
        }

        vector<pair<ll, ll>> target;
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                if (s[i][j] == '.' && isNextToRed(i, j)) target.emplace_back(i, j);
            }
        }

        for (const auto &[i, j] : target) {
            s[i][j] = '@';
            dfs(rest - 1);
            s[i][j] = '.';
        }
    };

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (s[i][j] == '.') {
                s[i][j] = '@';
                dfs(k-1);
                s[i][j] = '.';
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}