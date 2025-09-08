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
    int n;
    cin >> n;
    int aMax = -1e9 - 1;
    int bMax = -1e9 - 1;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        aMax = max(aMax, a);
    }
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        bMax = max(bMax, b);
    }
    cout << aMax + bMax << endl;

    return 0;
}