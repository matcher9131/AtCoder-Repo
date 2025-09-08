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
    ll n;
    cin >> n;
    unordered_map<ll, ll> memo;
    memo[1] = 0;

    function<ll(ll)> op = [&](ll x) -> ll {
        if (memo.contains(x)) return memo[x];
        return memo[x] = x + op(x/2) + op((x+1)/2);
    };

    cout << op(n) << endl;

    return 0;
}