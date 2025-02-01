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
    vector<int> a(n);
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> s[i];
    }

    int ans = 0;
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == "L") {
            if (l > -1) {
                ans += abs(a[i] - l);
            }
            l = a[i];
        } else {
            if (r > -1) {
                ans += abs(a[i] - r);
            }
            r = a[i];
        }
    }

    cout << ans << endl;

    return 0;
}