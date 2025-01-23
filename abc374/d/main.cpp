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

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    int n;
    double s, t;
    cin >> n >> s >> t;
    vector<double> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    int bitMax = 1 << n;
    double ans = 1e18;
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = i;
    }
    do {
        for (int bit = 0; bit < bitMax; ++bit) {
            double elapsed = 0;
            double x = 0, y = 0;
            for (int i = 0; i < n; ++i) {
                int j = perm[i];
                if ((bit >> i) & 1) {
                    elapsed += dist(x, y, a[j], b[j]) / s;
                    elapsed += dist(c[j], d[j], a[j], b[j]) / t;
                    x = c[j];
                    y = d[j];
                } else {
                    elapsed += dist(x, y, c[j], d[j]) / s;
                    elapsed += dist(a[j], b[j], c[j], d[j]) / t;
                    x = a[j];
                    y = b[j];
                }
            }
            ans = min(ans, elapsed);
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << setprecision(15) << ans << endl;

    return 0;
}