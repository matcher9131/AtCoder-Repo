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
    string s, t;
    cin >> s >> t;

    auto rle = [&](string &s) -> vector<pair<char, ll>> {
        vector<pair<char, ll>> res;
        ll n = s.size();
        ll left = 0;
        for (ll i = 0; i < n; ++i) {
            if (i == n-1 || s[i+1] != s[i]) {
                res.emplace_back(s[i], i+1 - left);
                left = i+1;
            }
        }
        return res;
    };

    vector<pair<char, ll>> rls = rle(s), rlt = rle(t);
    if (rls.size() != rlt.size()) {
        cout << "No" << endl;
    } else {
        ll m = rls.size();
        for (ll i = 0; i < m; ++i) {
            if (rls[i].first != rlt[i].first) {
                cout << "No" << endl;
                return 0;
            } else if (rls[i].second == 1 && rlt[i].second > 1) {
                cout << "No" << endl;
                return 0;
            } else if (rls[i].second > rlt[i].second) {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }

    return 0;
}