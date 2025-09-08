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
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<int> rank(n, -1);

    auto getMax = [&]() -> int {
        int m = -1;
        for (int i = 0; i < n; ++i) {
            if (rank[i] != -1) continue;
            m = max(m, p[i]);
        }
        return m;
    };

    int r = 1;
    while (true) {
        int m = getMax();
        if (m == -1) break;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i] == m) {
                rank[i] = r;
                ++k;
            }
        }
        r += k;
    }

    for (int i = 0; i < n; ++i) {
        cout << rank[i] << endl;
    }

    return 0;
}