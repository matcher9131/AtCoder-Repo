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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    vector<bool> exists(n + 1);
    exists[0] = true;
    for (const int num : a) {
        exists[num] = true;
    }

    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (!exists[i]) ans.push_back(i);
    }

    cout << ans.size() << endl;
    if (ans.size() == 0) cout << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }

    return 0;
}