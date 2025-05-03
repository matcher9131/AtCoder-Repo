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
    vector<string> s0(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> s0[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    
    vector<string> s1(n, string(n, '_')), s2(n, string(n, '_')), s3(n, string(n, '_'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s1[j][n-1-i] = s0[i][j];
            s2[n-1-i][n-1-j] = s0[i][j];
            s3[n-1-j][i] = s0[i][j];
        }
    }

    int ans0 = 0, ans1 = 1, ans2 = 2, ans3 = 3;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s0[i][j] != t[i][j]) ++ans0;
            if (s1[i][j] != t[i][j]) ++ans1;
            if (s2[i][j] != t[i][j]) ++ans2;
            if (s3[i][j] != t[i][j]) ++ans3;
        }
    }

    cout << min({ans0, ans1, ans2, ans3}) << endl;
    
    return 0;
}