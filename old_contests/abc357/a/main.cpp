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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int hi;
        cin >> hi;
        m -= hi;
        if (m < 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;

    return 0;
}