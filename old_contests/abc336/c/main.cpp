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
    
    string ans = "";
    do {
        ans.push_back('0' + (char)(2 * (n % 5)));
        n /= 5;
    } while (n > 0);
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    return 0;
}