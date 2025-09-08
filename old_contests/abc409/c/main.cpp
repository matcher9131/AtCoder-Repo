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
    int n, l;
    cin >> n >> l;
    if (l % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> c(l);
    c[0] = 1;
    int last = 0;
    for (int i = 1; i < n; ++i) {
        int di;
        cin >> di;
        int ai = (last + di) % l;
        ++c[ai];
        last = ai;
    }

    ll ans = 0;
    for (int i = 0; i < l / 3; ++i) {
        ans += (ll)c[i] * c[i + l/3] * c[i + l/3*2];
    }

    cout << ans << endl;
    return 0;
}