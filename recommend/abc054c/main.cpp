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
    vector<unordered_set<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].insert(b);
        g[b].insert(a);
    }

    vector<int> perm(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        perm[i] = i + 1;
    }

    auto reaches = [&]() {
        int cv = 0;
        for (const int v : perm) {
            if (g[cv].contains(v)) {
                cv = v;
            } else {
                return false;
            }
        }
        return true;
    };

    int ans = 0;
    do {
        if (reaches()) ++ans;
    } while (next_permutation(perm.begin(), perm.end()));

    cout << ans << endl;
    return 0;
}