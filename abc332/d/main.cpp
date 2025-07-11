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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> b[i][j];
        }
    }

    vector<vector<int>> bRowSorted = b;
    vector<int> aRowIndex(h, -1);
    vector<bool> bUsedRow(h);
    for (int i = 0; i < h; ++i) {
        sort(bRowSorted[i].begin(), bRowSorted[i].end());
    }
    for (int i = 0; i < h; ++i) {
        vector<int> c = a[i];
        sort(c.begin(), c.end());
        for (int j = 0; j < h; ++j) {
            if (c == bRowSorted[j] && !bUsedRow[j]) {
                aRowIndex[i] = j;
                bUsedRow[j] = true;
            }
        }
    }
    if (any_of(aRowIndex.begin(), aRowIndex.end(), [](int val) { return val == -1; })) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < h-1; ++i) {
        for (int j = h-1; j >= i+1; --j) {
            if (aRowIndex[j-1] > aRowIndex[j]) {
                swap(aRowIndex[j-1], aRowIndex[j]);
                swap(a[j-1], a[j]);
                ++ans;
            }
        }
    }

    vector<int> aColIndex(w);
    for (int j = 0; j < w; ++j) {
        aColIndex[j] = find(b[0].begin(), b[0].end(), a[0][j]) - b[0].begin();
    }
    for (int i = 1; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] != b[i][aColIndex[j]]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < w-1; ++i) {
        for (int j = w-1; j >= i+1; --j) {
            if (aColIndex[j-1] > aColIndex[j]) {
                swap(aColIndex[j-1], aColIndex[j]);
                ++ans;
            }
        }
    }

    cout << ans << endl;
    return 0;
}