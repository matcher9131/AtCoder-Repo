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
    int n, nq;
    cin >> n >> nq;
    vector<int> x(nq), y(nq), z(nq);
    vector<ll> w(nq);
    for (int qi = 0; qi < nq; ++qi) {
        cin >> x[qi] >> y[qi] >> z[qi] >> w[qi];
        --x[qi];
        --y[qi];
        --z[qi];
    }

    auto meets = [&](int bi, int bit) -> bool {
        for (int qi = 0; qi < nq; ++qi) {
            if (((bit & 1 << x[qi]) || (bit & 1 << y[qi]) || (bit & 1 << z[qi])) != !!(w[qi] & 1LL << bi)) return false;
        }
        return true;
    };

    mint ans = 1;
    for (int bi = 0; bi < 60; ++bi) {
        mint count = 0;
        for (int bit = 0; bit < (1 << n); ++bit) {
            if (meets(bi, bit)) ++count;
        }
        ans *= count;
    }

    cout << ans.val() << endl;

    return 0;
}