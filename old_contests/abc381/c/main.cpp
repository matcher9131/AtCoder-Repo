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
    string s;
    cin >> n >> s;

    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] != '1') continue;
        int l1 = i;
        for (; i < n; ++i) {
            if (s[i] != '1') break;
        }
        if (i + 1 < n && s[i] == '/' && s[i+1] == '2') {
            int r1 = i, l2 = i + 1;
            for (++i; i < n; ++i) {
                if (s[i] != '2') break;
            }
            int suc = min(r1- l1, i - l2);
            ans = max(ans, 2 * suc + 1);
            --i;
        }
    }

    cout << ans << endl;

    return 0;
}