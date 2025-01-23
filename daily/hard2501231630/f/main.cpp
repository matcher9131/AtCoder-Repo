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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ok = 1e9 + 1;
    int ng = -1;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        int na = upper_bound(a.begin(), a.end(), mid) - a.begin();
        int nb = b.end() - lower_bound(b.begin(), b.end(), mid);
        if (na >= nb) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}