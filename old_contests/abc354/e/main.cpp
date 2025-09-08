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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    unsigned m = 1U << n;

    vector<int> dp(m);
    for (unsigned bit = 0; bit < m; ++bit) {
        if (popcount(bit) < 2) {
            dp[bit] = -1;
        } else {
            int result = 1;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if ((bit & (1U << i)) && (bit & (1U << j))) {
                        if (a[i] == a[j] || b[i] == b[j]) {
                            unsigned bit2 = bit ^ (1U << i) ^ (1U << j);
                            result = min(result, dp[bit2]);
                        }
                    }
                }
            }
            dp[bit] = -result;
        }
    }
    
    cout << (dp[m - 1] == 1 ? "Takahashi" : "Aoki") << endl;
    return 0;
}