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
    char s1, s2, t1, t2;
    cin >> s1 >> s2 >> t1 >> t2;
    int x = abs(s2 - s1);
    int y = abs(t2 - t1);
    x = min(x, 5-x);
    y = min(y, 5-y);

    cout << (x == y ? "Yes" : "No") << endl;
    return 0;
}