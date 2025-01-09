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
    vector<tuple<int, int, char>> p(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        p[i] = make_tuple(x, y, c);
    }

    sort(p.begin(), p.end(), [](const tuple<int, int, char>& a, const tuple<int, int, char>& b) {
        int ax = get<0>(a);
        int bx = get<0>(b);
        return ax == bx ? get<1>(a) < get<1>(b) : ax < bx;
    });
    
    int minY = n + 1;
    for (const auto [x, y, c] : p) {
        if (c == 'W') {
            minY = min(minY, y);
        } else if (y >= minY) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}