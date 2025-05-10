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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<int> s;
    int i = 0;
    for (; i < n; ++i) {
        s.insert(a[i]);
        if ((int)s.size() == m) break;
    }

    if ((int)s.size() == m) {
        cout << n - i << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}