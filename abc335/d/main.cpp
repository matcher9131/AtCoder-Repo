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
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));

    int dir = 0;
    int i = 0, j = 0;
    for (int k = 1; k < n * n; ++k) {
        g[i][j] = k;
        switch (dir) {
            case 0:
                if (j < n-1 && g[i][j+1] == 0) ++j;
                else {
                    dir = 1;
                    ++i;
                } break;
            case 1:
                if (i < n-1 && g[i+1][j] == 0) ++i;
                else {
                    dir = 2;
                    --j;
                } break;
            case 2:
                if (j > 0 && g[i][j-1] == 0) --j;
                else {
                    dir = 3;
                    --i;
                } break;
            case 3:
                if (i > 0 && g[i-1][j] == 0) --i;
                else {
                    dir = 0;
                    ++j;
                } break;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)g[i].size(); ++j) {
            if (g[i][j] == 0) cout << "T ";
            else cout << g[i][j] << " \n"[j == (int)g[i].size() - 1];
        }
    }

    return 0;
}