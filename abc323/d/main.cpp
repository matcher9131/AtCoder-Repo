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
    int n;
    cin >> n;
    map<ll, ll> s;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        ll si, ci;
        cin >> si >> ci;
        s.emplace(si, ci);
        sum += ci;
    }

    for (const auto &[si, ci] : s) {
        s[2 * si] += ci / 2;
        sum -= ci / 2;
    }

    cout << sum << endl;

    return 0;
}