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
    map<string, ll> dic;
    dic["Ocelot"] = 0;
    dic["Serval"] = 1;
    dic["Lynx"] = 2;
    string x, y;
    cin >> x >> y;
    ll xi = dic[x];
    ll yi = dic[y];

    cout << (xi >= yi ? "Yes" : "No") << endl;


    return 0;
}