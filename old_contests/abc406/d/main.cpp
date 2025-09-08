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
    int h, w, n;
    cin >> h >> w >> n;
    map<int, set<int>> x, y;
    for (int i = 0; i < n; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        --xi;
        --yi;
        x[xi].insert(yi);
        y[yi].insert(xi);
    }

    int nq;
    cin >> nq;
    while (nq--) {
        int t, v;
        cin >> t >> v;
        --v;
        if (t == 1) {
            cout << x[v].size() << endl;
            for (const int yi : x[v]) {
                y[yi].erase(v);
            }
            x.erase(v);
        } else {
            cout << y[v].size() << endl;
            for (const int xi : y[v]) {
                x[xi].erase(v);
            }
            y.erase(v);
        }
    }

    return 0;
}