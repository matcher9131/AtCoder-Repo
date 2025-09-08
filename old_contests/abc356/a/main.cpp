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
    int n, l, r;
    cin >> n >> l >> r;
    --l;
    --r;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    reverse(a.begin() + l, a.begin() + r + 1);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}