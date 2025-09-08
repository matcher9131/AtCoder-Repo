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

constexpr int INF = 1e8;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> indexMap(1e6+1);
    for (int i = 0; i < n; ++i) {
        indexMap[a[i]].push_back(i);
    }

    int ans = INF;
    for (const auto& indices : indexMap) {
        if (indices.size() < 2) continue;
        for (int i = 1; i < indices.size(); ++i) {
            ans = min(ans, indices[i] - indices[i - 1]);
        }
    }

    cout << (ans == INF ? -1 : ans + 1) << endl;

    return 0;
}