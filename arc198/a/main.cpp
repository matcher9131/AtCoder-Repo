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
using ull = unsigned long long;
using ll = long long;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }

    int count = n / 2;
    cout << count << endl;
    for (int i = 0; i < count; ++i) {
        cout << (i + 1) * 2 << endl;
    }

    return 0;
}