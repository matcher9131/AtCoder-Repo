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
    ll n;
    cin >> n;
    --n;
    vector<int> smallAns{0,1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99};
    if (n <= 18) {
        cout << smallAns[n] << endl;
        return 0;
    }

    vector<ll> s(36);
    s[0] = -1;
    s[1] = 0;
    s[2] = 10;
    s[3] = 19;
    for (int i = 3; i < 35; ++i) {
        s[i + 1] = s[i] + 9 * (ll)pow(10, (i - 1) / 2);
    }

    auto it = upper_bound(s.begin(), s.end(), n);
    --it;
    int numDigits = it - s.begin();
    int d = (it - s.begin() + 1) / 2;
    ll rest = n - *it;
    string ans(numDigits, '_');
    for (int i = 0; i < d; ++i) {
        ll numOptions = (ll)pow(10, d - 1 - i);
        ans[i] = ans[numDigits - 1 - i] = (char)((i == 0 ? '1' : '0') + rest / numOptions);
        rest %= numOptions;
    }

    cout << ans << endl;

    return 0;
}