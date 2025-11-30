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

    vector<string> ans{ "b" };
    while (true) {
        string t = ans.back();
        string t1 = "a" + t + "c";
        string t2 = "c" + t1 + "a";
        string t3 = "b" + t2 + "b";
        ans.push_back(t1);
        ans.push_back(t2);
        ans.push_back(t3);
        if ((ll)t3.size() > 100) break;
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        if (s == ans[i]) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}