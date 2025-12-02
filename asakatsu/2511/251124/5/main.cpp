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

    auto getRes = [&](bool isWolf0, bool isWolf1) -> vector<bool> {
        vector<bool> isWolf(n);
        isWolf[0] = isWolf0, isWolf[1] = isWolf1;
        for (ll i = 1; i < n-1; ++i) {
            isWolf[i+1] = ((s[i] == 'o') ^ isWolf[i]) ? isWolf[i-1] : !isWolf[i-1];
        }
        return (isWolf0 ^ (s[0] == 'o')) == (isWolf[1] == isWolf[n-1]) && (isWolf[n-1] ^ (s[n-1] == 'o')) == (isWolf[n-2] == isWolf[0]) ? isWolf : vector<bool>();
    };

    vector<pair<bool, bool>> v{ {false, false}, {false, true}, {true, false}, {true, true} };
    for (const auto &[w0, w1] : v) {
        auto res = getRes(w0, w1);
        if (res.empty()) continue;
        for (ll i = 0; i < n; ++i) {
            cout << (res[i] ? "W" : "S");
        }
        cout << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}