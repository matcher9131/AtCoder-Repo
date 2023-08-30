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
using namespace std;
using ll = long long;


int main() {
    int n, m, cq;
    cin >> n >> m >> cq;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        ++a[l][r];
    }
    vector<vector<int>> s(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s[i + 1][j + 1] = a[i][j] + s[i + 1][j] + s[i][j + 1] - s[i][j];
        }
    }

    vector<int> p(cq), q(cq);
    for (int i = 0; i < cq; ++i) {
        cin >> p[i] >> q[i];
        --p[i];
        --q[i];
    }
    for (int i = 0; i < cq; ++i) {
        int l = p[i];
        int r = q[i] + 1;
        cout << s[r][r] - s[l][r] - s[r][l] + s[l][l] << endl;
    }

    return 0;
}