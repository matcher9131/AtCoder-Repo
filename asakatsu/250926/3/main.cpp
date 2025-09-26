#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/math>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    vector<vector<ll>> m{
        {0},
        {1},
        {6, 2, 4, 8},
        {1, 3, 9, 7},
        {6, 4},
        {5},
        {6},
        {1, 7, 9, 3},
        {6, 8, 4, 2},
        {1, 9}
    };

    cout << m[a%10][atcoder::pow_mod(b, c, m[a%10].size())] << endl;

    return 0;
}