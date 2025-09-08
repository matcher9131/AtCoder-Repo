#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    string s;
    cin >> n >> s;

    int ast = s.find('*');
    int l = s.find_first_of('|');
    int r = s.find_last_of('|');

    cout << (l < ast && ast < r ? "in" : "out") << endl;

    return 0;
}