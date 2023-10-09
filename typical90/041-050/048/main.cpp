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
    int n, k;
    cin >> n >> k;
    vector<ll> x;
    x.reserve(2 * n);
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        x.push_back(b);
        x.push_back(a - b);
    }
    sort(x.begin(), x.end(), greater<ll>());

    cout << accumulate(x.begin(), x.begin() + k, 0LL) << endl;

    return 0;
}