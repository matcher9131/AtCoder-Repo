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
    vector<int> c(n);
    vector<int> b;
    for (int i = 1; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i < n; ++i) {
        int ai;
        cin >> ai;
        if (ai > 0) b.push_back(i);
    }

    int ans = 0;
    while (!b.empty()) {
        int r = b.back();
        int l = r;
        b.pop_back();
        int next = b.empty() ? 0 : b.back();
        while (l > next) {
            int nl = l;
            for (int i = l; i <= r; ++i) {
                nl = min(nl, i - c[i]);
            }
            ++ans;
            l = nl;
        }
    }
    
    cout << ans << endl;
    return 0;
}