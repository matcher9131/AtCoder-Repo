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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        c.push_back(a[i]);
    }
    sort(c.begin(), c.end());

    for (int i = 0; i < n + m - 1; ++i) {
        if (find(a.begin(), a.end(), c[i]) != a.end() && find(a.begin(), a.end(), c[i+1]) != a.end()) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}