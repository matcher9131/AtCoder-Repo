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

const double PI = acos(-1);

int main() {
    int t;
    double l, x, y;
    int q;
    cin >> t >> l >> x >> y >> q;
    vector<double> e(q);
    for (int i = 0; i < q; ++i) {
        cin >> e[i];
    }

    cout << setprecision(15);
    for (const double ei : e) {
        double theta = 2 * PI * ei / t;
        double yi = l / 2 * sin(-theta);
        double zi = l / 2 * (1 - cos(theta));
        double d = sqrt(x * x + (y - yi) * (y - yi));
        double ans = atan2(zi, d) * 180.0 / PI;
        cout << ans << endl;
    }

    return 0;
}