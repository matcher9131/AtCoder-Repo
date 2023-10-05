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
    ll a, b, c;
    cin >> a >> b >> c;

    ll t = 1;
    for (int i = 0; i < b; ++i) {
        t *= c;
    }

    cout << (a < t ? "Yes" : "No") << endl;

    return 0;
}