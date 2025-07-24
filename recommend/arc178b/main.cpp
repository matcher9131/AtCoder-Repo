#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

mint base10 = 10;

mint count(int i) {
    return base10.pow(i) - base10.pow(i-1);
}

mint sum(int i) {
    mint start = base10.pow(i-1);
    mint end = base10.pow(i) - 1;
    return (start + end) * count(i) / 2;
}

void solve() {
    ll a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    if (a1 > a2) swap(a1, a2);

    if (a3 == a2) {
        // 繰り上がらない
        if (a1 < a2) {
            // f(x1) = c(a2) - x1
            mint ans = count(a1) * count(a2) - sum(a1);
            cout << ans.val() << endl;
        } else {
            // a1 == a2
            // f(x1) = max{ 0, c(a2) - x1 }
            mint ans = (1 + 8 * base10.pow(a2-1)) * 8 * base10.pow(a2-1) / 2;
            cout << ans.val() << endl;
        }
    } else if (a3 == a2 + 1) {
        // 繰り上がる
        if (a1 < a2) {
            // f(x1) = x1
            cout << sum(a1).val() << endl;
        } else {
            // a1 == a2
            // f(x1) = min{ x1, c(a2) }
            mint ans = sum(a1);
            ans -= (base10.pow(a2 - 1) - 1) * base10.pow(a2 - 1) / 2;
            cout << ans.val() << endl;
        }
    } else {
        cout << 0 << endl;
    }
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}