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
    double a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);

    if (b > a * 2 / sqrt(3)) {
        cout << setprecision(15) << a * 2 / sqrt(3) << endl;
        return 0;
    }

    double theta = atan((2 * b - sqrt(3) * a) / a);
    cout << setprecision(15) << a / cos(theta) << endl;

    return 0;
}