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
    int M, D, y, m, d;
    cin >> M >> D >> y >> m >> d;

    ++d;
    if (d > D) {
        ++m;
        d = 1;
    }
    if (m > M) {
        ++y;
        m = 1;
    }

    cout << y << " " << m << " " << d << endl;

    return 0;
}