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
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    vector<string> t(m);
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
    }

    auto same = [&](int si, int sj) -> bool {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[si+i][sj+j] != t[i][j]) return false;
            }
        }
        return true;
    };

    for (int si = 0; si < n - m + 1; ++si) {
        for (int sj = 0; sj < n - m + 1; ++sj) {
            if (same(si, sj)) {
                cout << si + 1 << " " << sj + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}