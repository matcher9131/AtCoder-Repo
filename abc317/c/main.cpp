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
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n, vector<ll>(n, -1));
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a][b] = c;
        g[b][a] = c;
    }

    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = i;
    }

    ll dmax = 0;
    do {
        ll d = 0;
        for (int i = 1; i < n; ++i) {
            int from = perm[i - 1];
            int to = perm[i];
            if (g[from][to] == -1) break;
            d += g[from][to];
        }
        dmax = max(dmax, d);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << dmax << endl;

    return 0;
}
