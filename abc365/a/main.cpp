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
    int y;
    cin >> y;

    int ans = y % 400 == 0 ? 366
        : y % 100 == 0 ? 365
        : y % 4 == 0 ? 366
        : 365;
    cout << ans << endl;

    return 0;
}