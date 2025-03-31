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
    vector<int> c(9);
    for (int i = 0; i < 9; ++i) {
        cin >> c[i];
    }
    int minCost = *min_element(c.begin(), c.end());
    int l = n / minCost;
    int rest = n - (l * minCost);

    string ans = "";
    while (l--) {
        for (int i = 8; i >= 0; --i) {
            if (c[i] - minCost <= rest) {
                ans += '1' + i;
                rest -= c[i] - minCost;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}