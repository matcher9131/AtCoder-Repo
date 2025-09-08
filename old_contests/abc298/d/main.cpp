#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll nq;
    cin >> nq;

    string s = "1";
    ll left = 0;
    mint ans = 1;
    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            char x;
            cin >> x;
            s += x;
            ans = ans * 10 + (x - '0');
        } else if (type == 2) {
            ans -= ((mint)10).pow((ll)s.size() - left - 1) * (s[left] - '0');
            ++left;
        } else {
            cout << ans.val() << endl;
        }
    }

    return 0;
}