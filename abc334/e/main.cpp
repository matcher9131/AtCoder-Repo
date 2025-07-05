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
#include <atcoder/modint>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> greenIndex(h, vector<int>(w, -1));
    int currentIndex = 0;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if (s[j] == '#') {
                greenIndex[i][j] = currentIndex++;
            }
        }
    }

    
    atcoder::dsu d(currentIndex);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (greenIndex[i][j] >= 0) {
                if (i+1 < h && greenIndex[i+1][j] >= 0) d.merge(greenIndex[i][j], greenIndex[i+1][j]);
                if (j+1 < w && greenIndex[i][j+1] >= 0) d.merge(greenIndex[i][j], greenIndex[i][j+1]);
            }
        }
    }

    int numConnection = d.groups().size();
    mint ans = 0;
    mint p = (mint)1 / (h*w - currentIndex);

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (greenIndex[i][j] >= 0) continue;
            unordered_set<int> g;
            if (i+1 < h && greenIndex[i+1][j] >= 0) g.insert(d.leader(greenIndex[i+1][j]));
            if (i-1 >= 0 && greenIndex[i-1][j] >= 0) g.insert(d.leader(greenIndex[i-1][j]));
            if (j+1 < w && greenIndex[i][j+1] >= 0) g.insert(d.leader(greenIndex[i][j+1]));
            if (j-1 >= 0 && greenIndex[i][j-1] >= 0) g.insert(d.leader(greenIndex[i][j-1]));
            ans += (numConnection + 1 - (int)g.size()) * p;
        }
    }

    cout << ans.val() << endl;

    return 0;
}