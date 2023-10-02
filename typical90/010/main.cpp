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
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        int c, p;
        cin >> c >> p;
        --c;
        a[c][i] = p;
    }
    int q;
    cin >> q;
    vector<int> l(q), r(q);
    for (int i = 0; i < q; ++i) {
        cin >> l[i] >> r[i];
        --l[i];
        --r[i];
    }

    for (int i = 1; i < n; ++i) {
        a[0][i] += a[0][i - 1];
        a[1][i] += a[1][i - 1];
    }

    for (int i = 0; i < q; ++i) {
        cout << a[0][r[i]] - (l[i] == 0 ? 0 : a[0][l[i] - 1]);
        cout << " ";
        cout << a[1][r[i]] - (l[i] == 0 ? 0 : a[1][l[i] - 1]);
        cout << endl;
    }

    return 0;
}