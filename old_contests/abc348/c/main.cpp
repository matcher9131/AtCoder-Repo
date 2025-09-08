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
    unordered_map<int, int> minBean;
    for (int i = 0; i < n; ++i) {
        int ai, ci;
        cin >> ai >> ci;
        if (minBean.contains(ci)) {
            minBean[ci] = min(minBean[ci], ai);
        } else {
            minBean[ci] = ai;
        }
    }

    int ans = 0;
    for (const auto &[_, a] : minBean) {
        ans = max(ans, a);
    }
    cout << ans << endl;

    return 0;
}