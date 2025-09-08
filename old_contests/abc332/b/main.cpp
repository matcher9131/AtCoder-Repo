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
    int k, g0, m0;
    cin >> k >> g0 >> m0;

    int g = 0, m = 0;
    for (int i = 0; i < k; ++i) {
        if (g == g0) g = 0;
        else if (m == 0) m = m0;
        else {
            int d = min(g0 - g, m);
            m -= d;
            g += d;
        }
    }

    cout << g << " " << m << endl;
    return 0;
}