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
    string s;
    cin >> n >> s;

    // (i + 1)s[i]の累積和
    vector<ll> sum(n);
    sum[0] = (ll)(s[0] - '0');
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + (i + 1) * (s[i] - '0');
    }

    // 解はΣ_{i=0}^{n-1} 10^{n-1-i} * sum[i]
    string ans = "";
    ll c = 0;
    int i = 0;
    while (true) {
        if (i < n) {
            c += sum[n - 1 - i];
        }
        ans += (char)(c % 10 + '0');
        c /= 10LL;
        ++i;
        if (i >= n && c == 0) break;
    }
    
    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}