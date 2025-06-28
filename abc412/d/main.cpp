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

    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = i;
    }

    auto countExists = [&](int i, int j) -> int {
        int result = 0;
        for (int k = 0; k < j - i; ++k) {
            if (g[perm[i+k]].contains(perm[i+(k+1)%(j-i)])) ++result;
        }
        return result;
    };

    int ans = 1e8;
    do {
        ans = min(ans, n + m - 2 * countExists(0, n));

        if (n == 8) {
            ans = min(ans, n + m - 2 * (countExists(0, 4) + countExists(4, 8)));
            ans = min(ans, n + m - 2 * (countExists(0, 5) + countExists(5, 8)));
            ans = min(ans, n + m - 2 * (countExists(0, 3) + countExists(3, 8)));
        } else if (n == 7) {
            ans = min(ans, n + m - 2 * (countExists(0, 4) + countExists(4, 7)));
            ans = min(ans, n + m - 2 * (countExists(0, 3) + countExists(3, 7)));
        } else if (n == 6) {
            ans = min(ans, n + m - 2 * (countExists(0, 3) + countExists(3, 6)));
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << ans << endl;
    return 0;
}