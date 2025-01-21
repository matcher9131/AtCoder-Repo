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
    int n, c;
    cin >> n >> c;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    int ans = 0;
    int last = -c;
    for (int i = 0; i < n; ++i) {
        if (t[i] - last >= c) {
            ++ans;
            last = t[i];
        }
    }

    cout << ans << endl;

    return 0;
}