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
using namespace std;
using ll = long long;

int h, w;
vector<string> g;

bool isTakCode(int i, int j) {
    for (int i2 = 0; i2 < 4; ++i2) {
        for (int j2 = 0; j2 < 4; ++j2) {
            if (i2 == 3 || j2 == 3) {
                if (g[i + i2][j + j2] != '.') return false;
                if (g[i + 8 - i2][j + 8 - j2] != '.') return false;
            } else {
                if (g[i + i2][j + j2] != '#') return false;
                if (g[i + 8 - i2][j + 8 - j2] != '#') return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> h >> w;
    g = vector<string>(h);
    for (int i = 0; i < h; ++i) {
        cin >> g[i];
    }

    for (int i = 0; i <= h - 9; ++i) {
        for (int j = 0; j <= w - 9; ++j) {
            if (isTakCode(i, j)) {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }

    return 0;
}