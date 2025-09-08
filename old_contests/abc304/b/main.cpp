#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    string n;
    cin >> n;

    string s(n.size(), '0');
    for (ll i = 0; i < min((int)n.size(), 3); ++i) {
        s[i] = n[i];
    }

    cout << s << endl;
    return 0;
}