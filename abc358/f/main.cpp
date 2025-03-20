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
    int n, m, k;
    cin >> n >> m >> k;

    if (n % 2 != k % 2 || k < n) {
        cout << "No" << endl;
        return 0;
    }

    int extra = k - n;
    // 0: 通らない、1: 右、2: 上、3: 左、4: 下
    vector<vector<int>> cells(n, vector<int>(m));
    if (n % 2 == 0 || n * m - k >= m - 1) {
        // 左右移動のみでマスを稼げるパターン
        for (int i = 0; i < n / 2; ++i) {
            int extraLeft = min(extra / 2, m - 1);
            extra -= 2 * extraLeft;
            if (extraLeft > 0) {
                for (int j = 0; j < extraLeft; ++j) {
                    cells[2*i][m-1-j] = 3;
                    cells[2*i+1][m-1-extraLeft+j] = 1;
                }
                cells[2*i][m-1-extraLeft] = 4;
                cells[2*i+1][m-1] = 4;
            } else {
                cells[2*i][m-1] = 4;
                cells[2*i+1][m-1] = 4;
            }
        }
        cells[n-1][m-1] = 4;
    } else {
        // 上下移動もしないとマス数が足りないパターン
        for (int i = 0; i < (n - 3) / 2; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                cells[2*i][m-1-j] = 3;
                cells[2*i+1][j] = 1;
            }
            cells[2*i][0] = 4;
            cells[2*i+1][m-1] = 4;
        }
        // とりあえず下から3段目を左に、左から1列目を下に行って左下隅に行く
        for (int j = 1; j < m; ++j) {
            cells[n-3][j] = 3;
        }
        cells[n-3][0] = 4;
        cells[n-2][0] = 4;
        // 一旦最下段を右移動で埋める
        for (int j = 0; j < m - 1; ++j) {
            cells[n-1][j] = 1;
        }
        // 上下移動でマスを稼ぐ
        for (int j = 0; j < (m - (n * m - k) - 1) / 2; ++j) {
            cells[n-1][2*j+1] = 2;
            cells[n-2][2*j+1] = 1;
            cells[n-2][2*j+2] = 4;
            cells[n-1][2*j+2] = 1;
        }
        cells[n-1][m-1] = 4;
    }

    cout << "Yes" << endl;
    string mid1 = "+";
    for (int j = 0; j < m; ++j) {
        mid1 += j == m - 1 ? "o+" : "o|";
    }
    string mid2 = "+";
    for (int j = 0; j < m; ++j) {
        mid2 += "-+";
    }
    vector<string> s(2 * n + 1);
    for (int i = 0; i < n; ++i) {
        s[2*i] = i == 0 ? string(2*m+1, '+') : mid2;
        s[2*i+1] = mid1;
        for (int j = 0; j < m; ++j) {
            s[2*i+1][2*j+1] = 'o';
        }
    }
    s[2*n] = string(2*m+1, '+');
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (cells[i][j] == 1) s[2*i+1][2*j+2] = '.';
            else if (cells[i][j] == 2) s[2*i][2*j+1] = '.';
            else if (cells[i][j] == 3) s[2*i+1][2*j] = '.';
            else if (cells[i][j] == 4) s[2*i+2][2*j+1] = '.';
        }
    }
    s[0][2*m-1] = 'S';
    s[2*n][2*m-1] = 'G';

    for (int i = 0; i < (int)s.size(); ++i) {
        cout << s[i] << endl;
    }

    return 0;
}