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
    int d, g;
    cin >> d >> g;
    g /= 100;
    vector<int> p(d), c(d);
    for (int i = 0; i < d; ++i) {
        cin >> p[i] >> c[i];
        c[i] /= 100;
    }

    function<int(int)> getAnswer = [&](int bit) {
        int count = 0;
        int scoreRemain = g;
        for (int i = 0; i < d; ++i) {
            if (bit & (1 << i)) {
                count += p[i];
                scoreRemain -= (i + 1) * p[i] + c[i];
            }
        }
        for (int i = d - 1; i >= 0; --i) {
            if (scoreRemain <= 0) return count;
            if (!(bit & (1 << i))) {
                int numSolve = min(p[i], (scoreRemain + i) / (i + 1));
                count += numSolve;
                scoreRemain -= (i + 1) * numSolve;
                if (numSolve == p[i]) scoreRemain -= c[i];
            }
        }
        return scoreRemain <= 0 ? count : 10000;
    };

    int ans = 10000;
    for (int bit = 0; bit < (1 << d); ++bit) {
        ans = min(ans, getAnswer(bit));
    }

    cout << ans << endl;

    return 0;
}