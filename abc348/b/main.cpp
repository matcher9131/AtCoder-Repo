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
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; ++i) {
        int max = 0;
        int ans = -1;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int dx = x[j] - x[i];
            int dy = y[j] - y[i];
            int d = dx * dx + dy * dy;
            if (d > max) {
                max = d;
                ans = j;
            }
        }
        cout << ans+1 << endl;
    }

    return 0;
}