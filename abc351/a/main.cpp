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
    vector<int> a(9);
    for (int i = 0; i < 9; ++i) {
        cin >> a[i];
    }
    vector<int> b(8);
    for (int i = 0; i < 8; ++i) {
        cin >> b[i];
    }

    cout << accumulate(a.begin(), a.end(), 0) - accumulate(b.begin(), b.end(), 0) + 1 << endl;

    return 0;
}