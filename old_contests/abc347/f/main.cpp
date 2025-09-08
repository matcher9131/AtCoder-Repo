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
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> s(n+1, vector<ll>(n+1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];
        }
    }

    vector<vector<ll>> b(n-m+1, vector<ll>(n-m+1));
    for (int i = 0; i < n-m+1; ++i) {
        for (int j = 0; j < n-m+1; ++j) {
            b[i][j] = s[i+m][j+m] - s[i][j+m] - s[i+m][j] + s[i][j];
        }
    }

    ll ans = 0;

    //

    return 0;
}