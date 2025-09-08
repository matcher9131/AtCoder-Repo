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
    int h, w, d;
    cin >> h >> w >> d;
    vector<int> fi;
    vector<int> fj;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if (s[j] == '.') {
                fi.push_back(i);
                fj.push_back(j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < fi.size(); ++i) {
        for (int j = i + 1; j < fi.size(); ++j) {
            int numCells = 0;
            for (int k = 0; k < fi.size(); ++k) {
                int dk = min(abs(fi[k] - fi[i]) + abs(fj[k] - fj[i]), abs(fi[k] - fi[j]) + abs(fj[k] - fj[j]));
                if (dk <= d) {
                    ++numCells;
                }
            }
            ans = max(ans, numCells);
        }
    }

    cout << ans << endl;

    return 0;
}