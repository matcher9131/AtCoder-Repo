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
    int r, x;
    cin >> r >> x;

    if (x == 1) {
        cout << (1600 <= r && r <= 2999 ? "Yes" : "No") << endl;
    } else {
        cout << (1200 <= r && r <= 2399 ? "Yes" : "No") << endl;
    }

    return 0;
}