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

    vector<int> c(26);
    for (const char ch : s) {
        ++c[ch - 'a'];
    }

    char ans = (char)('a' + (max_element(c.begin(), c.end()) - c.begin()));
    cout << ans << endl;

    return 0;
}