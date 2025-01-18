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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n, -1);
    unordered_map<int, int> last;
    for (int i = 0; i < n; ++i) {
        if (last.contains(a[i])) {
            b[i] = last[a[i]] + 1;
        }
        last[a[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        cout << b[i] << " \n"[i == n - 1];
    }

    return 0;
}