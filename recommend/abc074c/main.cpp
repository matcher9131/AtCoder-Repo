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

constexpr int NEG_INF = -1e8;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    a *= 100;
    b *= 100;

    int ansAll = a, ansSugar = 0;
    for (int ai = 0; ai <= f / a; ++ai) {
        for (int bi = 0; bi <= (f - ai * a) / b; ++bi) {
            if (ai == 0 && bi == 0) continue;
            int water = ai * a + bi * b;
            int maxSugar = min(f - water, water / 100 * e);
            for (int ci = 0; ci <= maxSugar / c; ++ci) {
                for (int di = 0; di <= (maxSugar - ci * c) / d; ++di) {
                    int sugar = ci * c + di * d;
                    if ((double)sugar / (water + sugar) > (double)ansSugar / ansAll) {
                        ansAll = water + sugar;
                        ansSugar = sugar;
                    }
                }
            }
        }
    }

    cout << ansAll << " " << ansSugar << endl;

    return 0;
}