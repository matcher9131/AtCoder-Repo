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
    int n, w;
    cin >> n >> w;
    // y_i, index
    vector<vector<pair<ll, int>>> g(w, vector<pair<ll, int>>());
    for (int i = 0; i < n; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        --xi;
        --yi;
        g[xi].emplace_back(yi, i);
    }
    for (int x = 0; x < w; ++x) {
        sort(g[x].begin(), g[x].end());
    }
    vector<ll> yOrder(n);
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < g[x].size(); ++y) {
            yOrder[g[x][y].second] = y;
        }
    }

    int numDeleteRows =  1e9;
    for (int x = 0; x < w; ++x) {
        numDeleteRows = min(numDeleteRows, (int)g[x].size());
    }

    vector<ll> d(numDeleteRows);
    ll last = -1;
    for (int y = 0; y < numDeleteRows; ++y) {
        ll t = last + 1;
        for (int x = 0; x < w; ++x) {
            t = max(t, g[x][y].first);
        }
        d[y] = t;
        last = t;
    }

    int nq;
    cin >> nq;
    while (nq--) {
        int t, ai;
        cin >> t >> ai;
        --ai;
        if (yOrder[ai] >= numDeleteRows) {
            cout << "Yes" << endl;
        } else {
            cout << (t > d[yOrder[ai]] ? "No" : "Yes") << endl;
        }
    }

    return 0;
}