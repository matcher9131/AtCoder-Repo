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
    string s;
    cin >> s;
    ll n = s.size();

    vector<bool> used(26);
    for (const char ch : s) {
        used[ch - 'a'] = true;
    }

    auto it = find(used.begin(), used.end(), false);
    if (it != used.end()) {
        cout << s + (char)(it - used.begin() + 'a') << endl;
    } else {
        string t = s;
        bool res = next_permutation(t.begin(), t.end());
        if (!res) {
            cout << -1 << endl;
        } else {
            ll i = 0;
            for (; i < n && s[i] == t[i]; ++i) cout << s[i];
            cout << t[i] << endl;
        }
    }

    return 0;
}