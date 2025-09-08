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

constexpr int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        a[i] = make_pair(ai, i);
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    vector<int> leftMinIndexes(n);
    int minIndex = INF;
    for (int i = 0; i < n; ++i) {
        minIndex = min(minIndex, a[i].second);
        leftMinIndexes[i] = minIndex;
    }

    for (int i = 0; i < m; ++i) {
        int j = upper_bound(a.begin(), a.end(), make_pair(b[i], INF)) - a.begin();
        if (j == 0) {
            cout << -1 << endl;
        } else {
            cout << leftMinIndexes[j - 1] + 1 << endl;
        }
    }

    return 0;
}