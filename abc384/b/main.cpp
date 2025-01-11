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
    int n, r;
    cin >> n >> r;
    vector<int> d(n), a(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i] >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (d[i] == 1) {
            if (r >= 1600 && r < 2800) {
                r += a[i];
            }
        } else {
            if (r >= 1200 && r < 2400) {
                r += a[i];
            }
        }
    }

    cout << r << endl;

    return 0;
}