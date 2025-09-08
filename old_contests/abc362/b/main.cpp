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

int sq(int x) { return x * x; }

int main() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    int d1 = sq(xb - xa) + sq(yb - ya);
    int d2 = sq(xc - xb) + sq(yc - yb);
    int d3 = sq(xa - xc) + sq(ya - yc);

    if (d1 + d2 == d3 || d2 + d3 == d1 || d3 + d1 == d2) {
        cout << "Yes" << endl; 
    } else {
        cout << "No" << endl;
    }

    return 0;
}