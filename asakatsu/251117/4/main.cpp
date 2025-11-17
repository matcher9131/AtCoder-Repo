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
    ll n = 7;

    set<string> s;
    s.insert("");

    for (ll i = 0; i < n; ++i) {
        set<string> ns;
        for (const string &t : s) {
            string nt = t;
            ns.insert(t + '0');
            for (ll j = 0; j < (ll)nt.size(); ++j) {
                nt[j] = nt[j] == '0' ? '1' : '0';
            }
            ns.insert("0" + nt);
        }
        swap(s, ns);
    }

    for (const string &t : s) {
        cout << t << endl;
    }

    return 0;
}