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
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<mint> x(n), y(m);
    for (int i = 0; i < n; ++i) {
        int xi;
        cin >> xi;
        x[i] = xi;
    }
    for (int j = 0; j < m; ++j) {
        int yj;
        cin >> yj;
        y[j] = yj;
    }

    mint ax = 0;
    for (int i = 0; i < n; ++i) {
        ax += (-n + 1 + 2 * i) * x[i];
    }
    mint ay = 0;
    for (int j = 0; j < m; ++j) {
        ay += (-m + 1 + 2 * j) * y[j];
    }

    cout << (ax * ay).val() << endl;
    return 0;
}