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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m = *max_element(a.begin(), a.end());
    vector<int> s(m + 1);
    for (const int ai : a) {
        ++s[ai];
    }
    vector<int> t(m + 1);
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; j += i) {
            // jはiの倍数、すなわちiはjの約数
            t[i] += s[j];
        }
    }
    vector<int> u(m + 1);
    for (int i = 1; i <= m; ++i) {
        if (t[i] < k) continue;
        for (int j = i; j <= m; j += i) {
            u[j] = max(u[j], i);
        }
    }
    
    for (const int ai : a) {
        cout << u[ai] << endl;
    }

    return 0;
}