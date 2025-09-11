#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    string s;
    cin >> s;
    ll n;
    cin >> n;

    cout << ((ll)s.size() >= n ? "Yes" : "No") << endl;

    return 0;
}