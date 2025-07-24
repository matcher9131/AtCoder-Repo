#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <numeric>
#include <functional>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;


int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    ll k = 0;
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '.') ++k;
        }
    }

    vector<vector<ll>> c(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        ll start = -1;
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '#') {
                if (start >= 0) {
                    for (ll k = start; k < j; ++k) {
                        c[i][k] += j - start;
                    }
                }
                start = -1;
            } else {
                if (start == -1) start = j;
            }
        }
        if (start >= 0) {
            for (ll k = start; k < w; ++k) {
                c[i][k] += w - start;
            }
        }
    }
    for (ll j = 0; j < w; ++j) {
        ll start = -1;
        for (ll i = 0; i < h; ++i) {
            if (s[i][j] == '#') {
                if (start >= 0) {
                    for (ll k = start; k < i; ++k) {
                        c[k][j] += i - start -1;
                    }
                }
                start = -1;
            } else {
                if (start == -1) start = i;
            }
        }
        if (start >= 0) {
            for (ll k = start; k < h; ++k) {
                c[k][j] += h - start - 1;
            }
        }
    }

    mint base2 = 2;
    mint ans = 0;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            ans += base2.pow(k - c[i][j]) * (base2.pow(c[i][j]) - 1);
        }
    }

    cout << ans.val() << endl;
    return 0;
}