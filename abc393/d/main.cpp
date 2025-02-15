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
    string s;
    cin >> n >> s;
    vector<int> one;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') one.push_back(i);
    }
    int m = one.size();

    if (m % 2 == 0) {
        int mLIndex = m / 2 - 1;
        int mRIndex = m / 2;
        if ((one[mLIndex] + one[mRIndex]) % 2 == 1) {
            // 中央値が非整数
            int medianLeft = (one[mLIndex] + one[mRIndex]) / 2;
            ll ans = 0;
            for (int i = 0; i < m; ++i) {
                int to = medianLeft + i - mLIndex;
                ans += abs(to - one[i]);
            }
            cout << ans << endl;
        } else {
            // 中央値が整数
            int median = (one[mLIndex] + one[mRIndex]) / 2;
            ll ansL = 0, ansR = 0;
            for (int i = 0; i < m; ++i) {
                int toL = median + i - mLIndex;
                ansL += abs(toL - one[i]);
                int toR = median + i - mRIndex;
                ansR += abs(toR - one[i]);
            }
            cout << min(ansL, ansR) << endl;
        }
    } else {
        int medianIndex = m / 2;
        int median = one[medianIndex];
        ll ans = 0;
        for (int i = 0; i < m; ++i) {
            int to = median - medianIndex + i;
            ans += abs(to - one[i]);
        }
        cout << ans << endl;
    }

    return 0;
}