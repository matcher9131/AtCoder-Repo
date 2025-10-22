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
    string s;
    cin >> s;

    vector<ll> one;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '1') one.push_back(i);
    }
    ll m = one.size();

    auto getAns = [&](ll left) -> ll {
        ll ans = 0;
        for (ll i = 0; i < m; ++i) {
            ans += abs(one[i] - (left + i));
        }
        return ans;
    };

    if (m%2) {
        ll median = one[m/2];
        ll left = median - m/2;
        cout << getAns(left) << endl;
    } else {
        ll ml = one[m/2 - 1];
        ll mr = one[m/2];
        if (ml % 2 == mr % 2) {
            ll left1 = (ml+mr)/2 - (m/2 - 1);
            ll left2 = (ml+mr)/2 - m/2;
            cout << min(getAns(left1), getAns(left2)) << endl;
            
        } else {
            ll left = (ml+mr+1)/2 - m/2;
            cout << getAns(left) << endl;
        }
    }

    return 0;
}