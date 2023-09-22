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
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    vector<int> r(h), c(w);
    for (int i = 0; i < h; ++i) {
        int s = 0;
        for (int j = 0; j < w; ++j) {
            s += a[i][j];
        }
        r[i] = s;
    }
    for (int j = 0; j < w; ++j) {
        int s = 0;
        for (int i = 0; i < h; ++i) {
            s += a[i][j];
        }
        c[j] = s;
    }

    for (int i = 0; i < h; ++i) {
        cout << r[i] + c[0] - a[i][0];
        for (int j = 1; j < w; ++j) {
            cout << " " << r[i] + c[j] - a[i][j];
        }
        cout << endl;
    }

    return 0;
}