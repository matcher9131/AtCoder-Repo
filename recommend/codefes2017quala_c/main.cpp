#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<ll> numChar(26);
    for (ll i = 0; i < h; ++i) {
        string si;
        cin >> si;
        for (ll j = 0; j < w; ++j) {
            ++numChar[si[j] - 'a'];
        }
    }

    int need1 = h % 2 && w % 2;
    int need2 = (h % 2) * (w / 2) + (w % 2) * (h / 2);
    int need4 = (h*w - need1 - 2*need2) / 4;

    if (need1) {
        auto it = find_if(numChar.begin(), numChar.end(), [](ll val) { return val % 2 == 1; });
        if (it == numChar.end()) {
            cout << "No" << endl;
            return 0;
        }
        --(*it);
        need1 = 0;
    }

    while (need2 > 0) {
        auto it = find_if(numChar.begin(), numChar.end(), [](ll val) { return val % 4 == 2; });
        if (it == numChar.end()) break;
        *it -= 2;
        --need2;
    }
    while (need2 >= 2) {
        auto it = find_if(numChar.begin(), numChar.end(), [](ll val) { return val >= 4; });
        if (it == numChar.end()) {
            cout << "No" << endl;
            return 0;
        }
        *it -= 4;
        need2 -= 2;
    }
    if (need2 > 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << (accumulate(numChar.begin(), numChar.end(), 0LL, [](ll acc, ll val) { return acc + val / 4; }) == need4 ? "Yes" : "No") << endl;

    return 0;
}