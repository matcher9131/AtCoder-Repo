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
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    int ans = (s == t.substr(0, n) ? 0 : 2) + (s == t.substr(m - n, n) ? 0 : 1);
    cout << ans << endl;

    return 0;
}