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
using namespace std;
using ll = long long;


int main() {
    vector<vector<int>> c(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> c[i][j];
        }
    }

    vector<int> perm{ 0, 1, 2, 3, 4, 5, 6, 7, 8 };

    auto isOK = [&]() {
        vector<vector<int>> row(3, vector<int>()), col(3, vector<int>());
        vector<int> diag1, diag2;
        for (const int p : perm) {
            int i = p / 3, j = p % 3;
            if (row[i].size() == 1 && row[i][0] == c[i][j]) return false;
            row[i].push_back(c[i][j]);
            if (col[j].size() == 1 && col[j][0] == c[i][j]) return false;
            col[j].push_back(c[i][j]);
            if (p == 0 || p == 4 || p == 8) {
                if (diag1.size() == 1 && diag1[0] == c[i][j]) return false;
                diag1.push_back(c[i][j]);
            }
            if (p == 2 || p == 4 || p == 6) {
                if (diag2.size() == 1 && diag2[0] == c[i][j]) return false;
                diag2.push_back(c[i][j]);
            }
        }
        return true;
    };

    int numer = 0;
    int denom = 0;
    do {
        ++denom;
        if (isOK()) ++numer;
    } while (next_permutation(perm.begin(), perm.end()));

    cout << setprecision(15) << (double)numer / denom << endl;

    return 0;
}
