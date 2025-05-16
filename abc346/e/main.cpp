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
    int h, w, m;
    cin >> h >> w >> m;
    vector<tuple<int, int, int>> q(m);
    for (int i = 0; i < m; ++i) {
        int t, a, x;
        cin >> t >> a >> x;
        --a;
        q[i] = {t, a, x};
    }
    reverse(q.begin(), q.end());

    map<int, ll> numColor;
    numColor[0] = (ll)h * w;
    set<int> coloredRow, coloredCol;
    for (const auto &[t, a, x] : q) {
        if (t == 1) {
            if (coloredRow.contains(a)) continue;
            int d = w - (int)coloredCol.size();
            if (d == 0) continue;
            numColor[x] += d;
            numColor[0] -= d;
            coloredRow.insert(a);
        } else {
            if (coloredCol.contains(a)) continue;
            int d = h - (int)coloredRow.size();
            if (d == 0) continue;
            numColor[x] += d;
            numColor[0] -= d;
            coloredCol.insert(a);
        }
    }

    cout << (int)numColor.size() - (numColor[0] == 0 ? 1 : 0) << endl;
    for (const auto &[k, v] : numColor) {
        if (v == 0) continue;
        cout << k << " " << v << endl;
    }

    return 0;
}