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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }

    vector<unordered_map<char, int>> rows(h);
    vector<unordered_map<char, int>> cols(w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ++rows[i][s[i][j]];
            ++cols[j][s[i][j]];
        }
    }

    while (true) {
        vector<int> targetRows;
        vector<int> targetCols;
        for (int i = 0; i < h; ++i) {
            if (rows[i].size() == 1 && rows[i].begin()->second >= 2) {
                targetRows.push_back(i);
            }
        }
        for (int j = 0; j < w; ++j) {
            if (cols[j].size() == 1 && cols[j].begin()->second >= 2) {
                targetCols.push_back(j);
            }
        }
        for (const int i : targetRows) {
            char c = rows[i].begin()->first;
            rows[i].erase(c);
            for (int j = 0; j < w; ++j) {
                if (cols[j].contains(c)) --cols[j][c];
                if (cols[j][c] == 0) cols[j].erase(c);
            }
        }
        for (const int j : targetCols) {
            // 行への操作ですでに取り除かれているケース
            if (cols[j].empty()) continue;
            char c = cols[j].begin()->first;
            cols[j].erase(c);
            for (int i = 0; i < h; ++i) {
                if (rows[i].contains(c)) --rows[i][c];
                if (rows[i][c] == 0) rows[i].erase(c);
            }
        }

        if (targetRows.empty() && targetCols.empty()) break;
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (const auto &[_, count] : rows[i]) {
            ans += count;
        }
    }

    cout << ans << endl;
    return 0;
}