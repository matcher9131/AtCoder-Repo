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

    for (const char c : s) {
        if (c == 'E') cout << 'W';
        if (c == 'S') cout << 'N';
        if (c == 'W') cout << 'E';
        if (c == 'N') cout << 'S';
    }
    cout << endl;

    return 0;
}