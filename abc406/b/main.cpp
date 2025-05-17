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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll max = 1;
    for (int i = 0; i < k; ++i) {
        max *= 10;
    }

    ll ans = 1;
    for (const ll ai : a) {
        if (ans > max / ai) {
            ans = 1;
        } else if (ans * ai == max) {
            ans = 1;
        } else {
            ans *= ai;
        }
    }

    cout << ans << endl;
    return 0;
}