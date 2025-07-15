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
    int n, k;
    cin >> n >> k;

    int kMax = (n-1) * (n-2) / 2;
    if (k > kMax) {
        cout << -1 << endl;
        return 0;
    }

    cout << n-1 + kMax - k << endl;
    for (int i = 0; i < n-1; ++i) {
        cout << i+1 << " " << n << endl;
    }
    int count = 0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            if (count == kMax - k) break;
            cout << i+1 << " " << j+1 << endl;
            ++count;
        }
        if (count == kMax - k) break;
    }

    return 0;
}