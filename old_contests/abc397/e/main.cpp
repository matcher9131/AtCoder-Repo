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
    int m, k;
    cin >> m >> k;
    int n = m * k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> size(n);
    function<void(int, int)> dfs = [&](int from, int parent) -> void {
        for (const int to : g[from]) {
            if (to == parent) continue;
            dfs(to, from);
        }

        size[from] = 1;
        int numChild = 0;
        for (const int child: g[from]) {
            if (child == parent) continue;
            size[from] += size[child];
            if (size[child] > 0) ++numChild;
        }
        if (size[from] < k) {
            if (numChild >= 2) {
                cout << "No" << endl;
                exit(0);
            }
        } else if (size[from] > k) {
            cout << "No" << endl;
            exit(0);
        } else {
            if (numChild >= 3) {
                cout << "No" << endl;
                exit(0);
            } else {
                size[from] = 0;
            }
        }
    };
    dfs(0, -1);

    cout << "Yes" << endl;
    return 0;
}