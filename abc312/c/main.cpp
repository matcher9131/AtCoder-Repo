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

int n, m;
vector<int> a, b;

bool isOK(int x) {
    int sell = upper_bound(a.begin(), a.end(), x) - a.begin();
    int buy = m - (lower_bound(b.begin(), b.end(), x) - b.begin());
    return sell >= buy;
}

int binary_search() {
    int ng = 0;
    int ok = 1e9 + 1;

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    
    return ok;
}

int main() {
    cin >> n >> m;
    a = vector<int>(n);
    b = vector<int>(m);
    set<int> c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c.insert(a[i]);
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        c.insert(b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << binary_search() << endl;

    return 0;
}