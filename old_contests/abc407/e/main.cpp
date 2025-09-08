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
        vector<ll> a(2*n);
        for (int i = 0; i < 2*n; ++i) {
            cin >> a[i];
        }
        priority_queue<ll> que;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            que.push(a[2*i]);
            if (i > 0) que.push(a[2*i-1]);
            ans += que.top();
            que.pop();
        }
        cout << ans << endl;
    }

    return 0;
}