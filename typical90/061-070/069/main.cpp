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
    ll n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << k << endl;
        return 0;
    } else if (n == 2) {
        cout << ((mint)k * (k - 1)).val() << endl;
        return 0;
    } else if (k < 3) {
        cout << 0 << endl;
        return 0;
    }

    vector<mint> pmk(64);
    pmk[0] = k - 2;
    for (int bit = 1; bit < 64; ++bit) {
        pmk[bit] = pmk[bit - 1] * pmk[bit - 1];
    }

    mint ans = 1;
    for (int bit = 0; bit < 64; ++bit) {
        if ((n - 2) & (1LL << bit)) {
            ans *= pmk[bit];
        }
    }
    ans *= k - 1;
    ans *= k;

    cout << ans.val() << endl;

    return 0;
}