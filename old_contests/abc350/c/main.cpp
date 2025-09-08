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
    vector<int> a(n), revA(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        revA[a[i]] = i;
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n-1; ++i) {
        if (a[i] == i) continue;
        int j = revA[i];
        ans.emplace_back(i, j);
        swap(a[i], a[j]);
        revA[a[j]] = j;
    }

    cout << ans.size() << endl;
    for (const auto &[i, j] : ans) {
        cout << i+1 << " " << j+1 << endl;
    }

    return 0;
}