#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    string s;
    cin >> s;

    ll n = s[0] - '0';
    ll m = s[2] - '0';
    if (m == 8) {
        ++n;
        m = 1;
    } else {
        ++m;
    }

    cout << n << "-" << m << endl;

    return 0;
}