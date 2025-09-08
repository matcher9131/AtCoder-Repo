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
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            int ai;
            cin >> ai;
            --ai;
            a[i][j] = ai;
        }
    }

    int current = 0;
    for (int i = 0; i < n; ++i) {
        current = current >= i ? a[current][i] : a[i][current];
    }

    cout << current + 1 << endl;

    return 0;
}