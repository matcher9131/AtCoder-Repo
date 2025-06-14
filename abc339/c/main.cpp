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
    ll sum = 0;
    ll minSum = 0;
    for (int i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        sum += ai;
        minSum = min(minSum, sum);
    }

    cout << -minSum + sum << endl;

    return 0;
}