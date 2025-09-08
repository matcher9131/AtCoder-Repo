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
    vector<ll> k(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }

    ll ans = 1e18;
    int bitMax = 1 << n;
    for (int bit = 0; bit < bitMax; ++bit) {
        ll a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            if ((bit >> i) & 1) a += k[i];
            else b += k[i];
        }
        ans = min(ans, max(a, b));
    }

    cout << ans << endl;

    return 0;
}