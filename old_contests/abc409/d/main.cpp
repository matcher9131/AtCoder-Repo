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

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int l = -1;
    for (int i = 0; i < n-1; ++i) {
        if (s[i] > s[i+1]) {
            l = i;
            break;
        }
    }
    if (l == -1) {
        cout << s << endl;
        return;
    }

    int r = n-1;
    for (int i = l+1; i < n; ++i) {
        if (s[l] < s[i]) {
            r = i-1;
            break;
        }
    }
    
    string t = s.substr(0, l) + s.substr(l+1, r-l) + s[l] + s.substr(r+1);
    cout << t << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}