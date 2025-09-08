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

    vector<vector<bool>> g(h, vector<bool>(w));
    int i = 0, j = 0, dir = 0;

    while (n--) {
        if (g[i][j]) {
            g[i][j] = false;
            dir += 3;
        } else {
            g[i][j] = true;
            ++dir;
        }
        dir %= 4;
        switch (dir) {
            case 0: i += h-1; break;
            case 1: ++j; break;
            case 2: ++i; break;
            case 3: j += w-1;
            default: break;
        }
        i %= h;
        j %= w;
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << (g[i][j] ? '#' : '.');
        }
        cout << endl;
    }

    return 0;
}