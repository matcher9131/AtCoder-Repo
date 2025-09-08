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
    ll n, l, d;
    cin >> n >> l >> d;
    double p = 1.0 / d;

    vector<double> dpy(2*n+1);
    dpy[0] = 1.0;
    dpy[1] = -1.0;
    for (int y = 0; y < l; ++y) {
        dpy[y+1] += dpy[y] * p;
        dpy[y+1+d] -= dpy[y] * p;
        dpy[y+1] += dpy[y];
    }
    for (int y = l; y < 2*n; ++y) {
        dpy[y+1] += dpy[y];
    }
    for (int y = 0; y < l; ++y) {
        dpy[y] = 0;
    }
    vector<double> sumDpy(2*n+1);
    for (int y = 1; y <= 2*n; ++y) {
        sumDpy[y] = sumDpy[y-1] + dpy[y];
    }
    double yBurst = sumDpy[2*n] - sumDpy[n];

    vector<double> win(2*n+1);
    for (int x = 0; x <= n; ++x) {
        win[x] = yBurst + (x > 0 ? sumDpy[x-1] : 0);
    }

    vector<double> dpx(2*n+2);
    // [x+1, x+d]におけるdpxの合計
    double sumDpx = 0;
    for (int x = n; x >= 0; --x) {
        sumDpx -= dpx[x+1+d];
        sumDpx += dpx[x+1];
        dpx[x] = max(win[x], sumDpx * p);
    }

    cout << setprecision(15) << dpx[0] << endl;

    return 0;
}