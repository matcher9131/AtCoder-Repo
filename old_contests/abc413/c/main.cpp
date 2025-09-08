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
    int nq;
    cin >> nq;
    queue<pair<int, int>> que;

    while (nq--) {
        int k;
        cin >> k;
        if (k == 1) {
            int c, x;
            cin >> c >> x;
            que.emplace(c, x);
        } else {
            int k;
            cin >> k;
            ll ans = 0;
            while (k > 0) {
                int dec = min(que.front().first, k);
                ans += (ll)dec * que.front().second;
                que.front().first -= dec;
                k -= dec;
                if (que.front().first == 0) que.pop();
            }
            cout << ans << endl;
        }
    }

    return 0;
}