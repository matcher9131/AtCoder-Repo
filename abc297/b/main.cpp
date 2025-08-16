#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    string s;
    cin >> s;

    ll b1 = s.find_first_of('B');
    ll b2 = s.find_last_of('B');
    if (b1 % 2 == b2 % 2) {
        cout << "No" << endl;
        return 0;
    }
    ll r1 = s.find_first_of('R');
    ll r2 = s.find_last_of('R');
    ll k = s.find('K');
    cout << (r1 < k && k < r2 ? "Yes" : "No") << endl;

    return 0;
}