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
    int r, g, b;
    string c;
    cin >> r >> g >> b >> c;

    if (c == "Red") {
        cout << min(g, b) << endl;
    } else if (c == "Green") {
        cout << min(r, b) << endl;
    } else {
        cout << min(r, g) << endl;
    }

    return 0;
}