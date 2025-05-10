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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll sum = accumulate(a.begin(), a.end(), 0LL);
    ll sqSum = 0;
    for (int i = 0; i < n; ++i) {
        sqSum += a[i] * a[i];
    }

    cout << (sum * sum - sqSum) / 2 << endl;

    return 0;
}