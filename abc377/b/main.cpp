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
    vector<string> s(8);
    for (int i = 0; i < 8; ++i) {
        cin >> s[i];
    }

    vector<vector<bool>> cells(8, vector<bool>(8));
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (s[i][j] == '#') {
                for (int k = 0; k < 8; ++k) {
                    cells[i][k] = true;
                    cells[k][j] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (!cells[i][j]) ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}