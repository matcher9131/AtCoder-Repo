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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    vector<vector<int>> r(h, vector<int>(26));
    vector<vector<int>> c(w, vector<int>(26));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ++r[i][s[i][j] - 'a'];
            ++c[j][s[i][j] - 'a'];
        }
    }

    int ch = h, cw = w;
    while (true) {
        if (ch <= 1 || cw <= 1) break;

        vector<pair<int, int>> dr;
        vector<pair<int, int>> dc;

        for (int i = 0; i < h; ++i) {
            for (int k = 0; k < 26; ++k) {
                if (r[i][k] == cw) {
                    dr.emplace_back(i, k);
                }
            }
        }
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < 26; ++k) {
                if (c[j][k] == ch) {
                    dc.emplace_back(j, k);
                }
            }
        }

        if (dr.size() == 0 && dc.size() == 0) break;

        for (const auto &[i, k] : dr) {
            r[i][k] = 0;
            for (int j = 0; j < w; ++j) {
                --c[j][k];
            }
            --ch;
        }

        for (const auto &[j, k] : dc) {
            c[j][k] = 0;
            for (int i = 0; i < h; ++i) {
                --r[i][k];
            }
            --cw;
        }
    }

    cout << ch * cw << endl;

    return 0;
}