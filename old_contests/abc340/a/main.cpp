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
    int a, b, d;
    cin >> a >> b >> d;

    for (int x = a; x <= b; x += d) {
        cout << (x == a ? "" : " ") << x;
    }
    cout << endl;

    return 0;
}