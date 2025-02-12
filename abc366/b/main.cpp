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
    vector<string> s(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        m = max(m, (int)s[i].size());
    }

    vector<string> t(m, string(n, ' '));
    vector<int> tjMax(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < s[i].size(); ++j) {
            t[j][n-1-i] = s[i][j];
            tjMax[j] = max(tjMax[j], n-1-i);
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < tjMax[i]; ++j) {
            if (t[i][j] == ' ') t[i][j] = '*';
            t[i] = t[i].substr(0, tjMax[i] + 1);
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << t[i] << endl;
    }

    return 0;
}