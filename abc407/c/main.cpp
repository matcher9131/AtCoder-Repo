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
    string s;
    cin >> s;
    int n = s.size();

    ll ans = 0;
    for (int i = n-1; i >= 0; --i) {
        int digit = (int)(s[i] - '0');
        ans += (digit + 10 - ans % 10) % 10;
    }

    cout << ans + n << endl;
    return 0;
}