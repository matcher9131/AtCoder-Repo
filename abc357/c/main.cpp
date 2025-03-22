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

    vector<vector<string>> lv(n + 1);
    lv[0] = { "#" };
    
    for (int i = 1; i <= n; ++i) {
        int side = (int)pow(3, i);
        lv[i] = vector<string>(side, string(side, '.'));
        for (int bi = 0; bi < 3; ++bi) {
            for (int bj = 0; bj < 3; ++bj) {
                if (bi == 1 && bj == 1) continue;
                int prevSide = side / 3;
                for (int pi = 0; pi < prevSide; ++pi) {
                    for (int pj = 0; pj < prevSide; ++pj) {
                        lv[i][bi * prevSide + pi][bj * prevSide + pj] = lv[i-1][pi][pj];
                    }
                }
            }
        }
    }

    for (const auto& row : lv[n]) {
        cout << row << endl;
    }
    return 0;
}