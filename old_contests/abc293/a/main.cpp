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
    int n = s.size();

    for (ll i = 0; i < n; i += 2) {
        swap(s[i], s[i+1]);
    }

    cout << s << endl;
    return 0;
}