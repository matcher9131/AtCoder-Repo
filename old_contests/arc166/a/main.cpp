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

bool judge(string x, string y) {
    for (int i = 0; i < x.size(); ++i) {
        if (y[i] == 'C') {
            if (x[i] == 'C') {
                return judge(x.substr(0, i), y.substr(0, i)) && judge(x.substr(i + 1), y.substr(i + 1));
            } else {
                return false;
            }
        }
    }
    int nxa = count(x.begin(), x.end(), 'A');
    int nxb = count(x.begin(), x.end(), 'B');
    int nya = count(y.begin(), y.end(), 'A');
    int nyb = y.size() - nya;
    if (nxa > nya || nxb > nyb) return false;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] == 'C') {
            if (nxa < nya) {
                x[i] = 'A';
                ++nxa;
            } else {
                x[i] = 'B';
            }
        }
    }
    int xi = 0, yi = 0;
    while (xi < x.size() && yi < y.size()) {
        while (x[xi] == 'B') ++xi;
        while (y[yi] == 'B') ++yi;
        if (xi > yi) return false;
        ++xi;
        ++yi;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        string x, y;
        cin >> n >> x >> y;
        cout << (judge(x, y) ? "Yes" : "No") << endl;
    }

    return 0;
}