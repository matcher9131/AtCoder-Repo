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
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<vector<int>> area(101, vector<int>(101));
    for (int i = 0; i < n; ++i) {
        for (int x = a[i]; x < b[i]; ++x) {
            for (int y = c[i]; y < d[i]; ++y) {
                ++area[x][y];
            }
        }
    }

    int answer = 0;
    for (int x = 0; x <= 100; ++x) {
        for (int y = 0; y <= 100; ++y) {
            if (area[x][y] > 0) ++answer;
        }
    }
    cout << answer << endl;

    return 0;
}
