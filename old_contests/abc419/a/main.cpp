#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    string s;
    cin >> s;

    if (s == "red") {
        cout << "SSS" << endl;
    } else if (s == "blue") {
        cout << "FFF" << endl;
    } else if (s == "green") {
        cout << "MMM" << endl;
    } else {
        cout << "Unknown" << endl;
    }

    return 0;
}