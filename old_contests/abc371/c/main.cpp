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
    int mg;
    cin >> mg;
    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < mg; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a][b] = true;
        g[b][a] = true;
    }
    int mh;
    cin >> mh;
    vector<vector<bool>> h(n, vector<bool>(n));
    for (int i = 0; i < mh; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        h[a][b] = true;
        h[b][a] = true;
    }
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }

    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = i;
    }

    int ans = 1e9;
    do {
        int sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (g[i][j] ^ h[perm[i]][perm[j]]) sum += a[perm[i]][perm[j]];
            }
        }
        ans = min(ans, sum);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << ans << endl;

    return 0;
}