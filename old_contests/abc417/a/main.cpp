#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, a, b;
    string s;
    cin >> n >> a >> b >> s;

    cout << s.substr(a, n-a-b) << endl;

    return 0;
}