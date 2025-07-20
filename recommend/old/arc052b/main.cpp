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
using namespace std;
using ll = long long;

const double PI = acos(-1);

double getVolume(double x, double r, double h, double left, double right) {
    double h1 = x + h - left;
    if (h1 > h) h1 = h;
    double h2 = x + h - right;
    if (h2 < 0) h2 = 0;
    double r1 = r * h1 / h;
    double r2 = r * h2 / h;
    return (r1 * r1 * h1 - r2 * r2 * h2) * PI / 3;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> x(n), r(n), h(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> r[i] >> h[i];
    }
    vector<int> a(q), b(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<double> sum(20001);
    for (int i = 0; i < n; ++i) {
        for (int hi = 0; hi < h[i]; ++hi) {
            int a = x[i] + hi;
            sum[a] += getVolume(x[i], r[i], h[i], a, a + 1);
        }
    }

    cout << setprecision(15);
    for (int i = 0; i < q; ++i) {
        double s = 0;
        for (int t = a[i]; t < b[i]; ++t) {
            s += sum[t];
        }
        cout << s << endl;
    }
    

    return 0;
}