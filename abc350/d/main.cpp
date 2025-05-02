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
#include <atcoder/dsu>
using namespace std;
using ll = long long;


int main() {
    int n, m;
    cin >> n >> m;
    atcoder::dsu d(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        d.merge(a, b);
    }

    ll ans = 0;
    for (const auto &group : d.groups()) {
        ll size = group.size();
        ans += size * (size - 1) / 2;
    }
    ans -= m;

    cout << ans << endl;
    return 0;
}