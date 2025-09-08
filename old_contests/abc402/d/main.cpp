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
    ll m;
    cin >> n >> m;
    map<int, ll> center;
    for (int i = 0; i < m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        --ai;
        --bi;
        int c = ai + bi;
        if (c > n) c -= n;
        ++center[c];
    }

    ll ans = m * (m + 1) / 2;
    for (const auto &[_, value] : center) {
        ans -= value * (value + 1) / 2; 
    }

    cout << ans << endl;
    return 0;
}