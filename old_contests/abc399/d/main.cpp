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
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int n2 = n * 2;
        vector<int> a(n2);
        for (int i = 0; i < n2; ++i) {
            cin >> a[i];
        }

        vector<vector<int>> rev(n+1);
        for (int i = 0; i < n2; ++i) {
            rev[a[i]].push_back(i);
        }

        int ans = 0;
        for (int i = 0; i < n2 - 3; ++i) {
            int x = a[i], y = a[i+1];
            if (x == y) continue;
            if (rev[x][1] == i) continue;
            int y2i = rev[y][0] == i+1 ? rev[y][1] : rev[y][0];
            if (y2i - (i + 1) == 1) continue;
            if (abs(rev[x][1] - y2i) == 1) ++ans;
        }

        cout << ans << endl;
    }

    return 0;
}