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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);

    vector<bool> visited(n);
    function<void(int,int)> dfs = [&](int from, int parent) -> void {
        int k;
        cin >> k;
        if (k == -1) exit(0);
        vector<int> v(k);
        for (int i = 0; i < k; ++i) {
            cin >> v[i];
            --v[i];
        }
        if (!visited[from]) {
            g[from] = v;
            visited[from] = true;
        }

        if (find(g[from].begin(), g[from].end(), n-1) != g[from].end()) {
            cout << n << endl;
            string s;
            cin >> s;
            exit(0);
        }

        for (const int to : g[from]) {
            if (visited[to]) continue;
            cout << to+1 << endl;
            dfs(to, from);
        }

        cout << parent+1 << endl;
        int k2;
        cin >> k2;
        if (k2 == -1) exit(0);
        for (int i = 0; i < k2; ++i) {
            int t;
            cin >> t; 
        }
    };
    dfs(0, -1);


    return 0;
}