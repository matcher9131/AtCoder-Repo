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
    ll k;
    cin >> n >> k;
    vector<int> x(n), a(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        --x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> db(60, vector<int>(n));
    db[0] = x;
    for (int j = 1; j < 60; ++j) {
        for (int i = 0; i < n; ++i) {
            db[j][i] = db[j-1][db[j-1][i]];
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = i;
    }

    for (int j = 0; j < 60; ++j) {
        if (k % 2) {
            for (int i = 0; i < n; ++i) {
                ans[i] = db[j][ans[i]];
            }
        }
        k /= 2;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[ans[i]] << " \n"[i == n - 1];
    }

    return 0;
}