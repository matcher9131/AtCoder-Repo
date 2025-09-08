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
    string s;
    cin >> s;
    int n = s.size();
    int m = 2 * n + 1;

    string t(m, '_');
    for (int i = 0; i < n; ++i) {
        t[2 * i + 1] = s[i];
    }
    
    vector<int> r(m);
    int i = 0, j = 0;
    while (i < m) {
        while (i - j >= 0 && i + j < m && t[i-j] == t[i+j]) {
            ++j;
        }
        r[i] = j;
        int k = 1;
        while (i - k >= 0 && k + r[i-k] < j) {
            r[i+k] = r[i-k];
            ++k;
        }
        i += k;
        j -= k;
    }

    for (int i = 0; i < m; ++i) {
        int len = r[i] - 1;
        int start = (i - r[i] + 1) / 2;
        if (start + len == n) {
            string ans = s;
            for (int j = start - 1; j >= 0; --j) {
                ans += s[j];
            }
            cout << ans << endl;
            return 0;
        }
    }

    return 0;
}