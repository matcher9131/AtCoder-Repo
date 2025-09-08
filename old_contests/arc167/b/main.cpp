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
using mint = atcoder::modint998244353;


int main() {
    ll a, b;
    cin >> a >> b;

    vector<mint> d;
    vector<bool> even;
    ll c = a;
    for (ll i = 2; i * i <= c; ++i) {
        ll e = 0;
        while (c % i == 0) {
            ++e;
            c /= i;
        }
        if (e > 0) {
            d.push_back((mint)e * b);
            even.push_back(e % 2 == 0 || b % 2 == 0);
        }
    }
    if (c > 1) {
        d.push_back(b);
        even.push_back(b % 2 == 0);
    }

    mint numDivisor = accumulate(d.begin(), d.end(), (mint)1, [](mint acc, mint value) {
        return acc * (value + 1);
    });
    bool isAllEven = all_of(even.begin(), even.end(), [](bool value) {
        return value;
    });

    mint ans = (isAllEven && b % 2 == 1) ? (numDivisor * b - 1) / 2 : numDivisor * b / 2;
    cout << ans.val() << endl;

    return 0;
}