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

int n, m;
vector<vector<int>> a;
vector<int> c;

bool isOK(int x) {
    unordered_set<int> unselected;
    int unsmax = m - n / x;
    while ((int)unselected.size() <= unsmax) {
        fill(c.begin(), c.end(), 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (unselected.find(a[i][j]) == unselected.end()) {
                    ++c[a[i][j]];
                    break;
                }
            }
        }
        auto it = max_element(c.begin(), c.end());
        //
        // cout << "max = " << *it << ", no. = " << it - c.begin() << endl;
        //
        if (*it <= x) return true;
        unselected.insert(it - c.begin());
    }
    return false;
}

int binary_search() {
    int ng = 0;
    int ok = n;

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        //
        // cout << "mid = " << mid << endl;
        //
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    
    return ok;
}

int main() {
    cin >> n >> m;
    a = vector<vector<int>>(n, vector<int>(m));
    c = vector<int>(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            --a[i][j];
        }
    }

    int answer = binary_search();

    cout << answer << endl;

    return 0;
}