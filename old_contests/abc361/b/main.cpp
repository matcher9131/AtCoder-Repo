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
    int n = 6;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    auto crosses = [](int l1, int r1, int l2, int r2) -> bool {
        return (l1 <= l2 && l2 < r1) || (l2 <= l1 && l1 < r2);
    };

    bool ans = true;
    for (int i = 0; i < 3; ++i) {
        ans &= crosses(a[i], a[3+i], b[i], b[3+i]);
    }

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}