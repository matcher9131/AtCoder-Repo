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
using namespace std;
using ll = long long;


int main() {
    ll n, a;
    double x, y;
    cin >> n >> a >> x >> y;

    unordered_map<ll, double> memo;
    memo[0] = 0;
    function<double(ll)> dfs = [&](ll i) {
        if (memo.contains(i)) return memo[i];
        return memo[i] = min(x + dfs(i / a), 1.2 * y + 0.2 * (dfs(i / 2) + dfs(i / 3) + dfs(i / 4) + dfs(i / 5) + dfs(i / 6)));
    };

    cout << setprecision(15) << dfs(n) << endl;
    return 0;
}