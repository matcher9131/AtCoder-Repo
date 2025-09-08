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
    int n, x;
    cin >> n >> x;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int sumLow = accumulate(a.begin(), a.end() - 1, 0);
    if (sumLow >= x) {
        cout << 0 << endl;
        return 0;
    }
    int sum = accumulate(a.begin() + 1, a.end() - 1, 0);
    if (x - sum <= a[n - 2]) {
        cout << x - sum << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}
