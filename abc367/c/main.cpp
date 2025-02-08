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
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    int numMax = (int)pow(5, n);

    vector<int> ans(n);
    auto meetsR = [&]() -> bool {
        for (int i = 0; i < n; ++i) {
            if (ans[i] > r[i]) return false;
        }
        return true;
    };
    for (int num = 0; num < numMax; ++num) {
        int m = num;
        for (int i = 0; i < n; ++i) {
            ans[n - 1 - i] = m % 5 + 1;
            m /= 5;
        }
        if (!meetsR()) continue;
        if (accumulate(ans.begin(), ans.end(), 0) % k != 0) continue;
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}