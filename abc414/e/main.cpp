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
    ll n;
    cin >> n;

    mint ans = 0;
    for (ll b = 1; b * b <= n; ++b) {
        ll q = (n-1) / b;
        ans += q * (b-1);
        if (b != q) ans += b * (q-1);
    }

    cout << ans.val() << endl;
    return 0;
}