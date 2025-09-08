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
    for (int i = 0; i < n-1; ++i) {
        int d;
        cin >> d;
        a[i+1] = a[i] + d;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            cout << a[j] - a[i] << " \n"[j == n - 1];
        }
    }

    return 0;
}