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
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    bool ans = x < y
        ? x < z && z < y
        : y < z && z < x;
    
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}