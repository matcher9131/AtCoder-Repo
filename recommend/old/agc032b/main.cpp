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

    cout << n * (n - 1) / 2 - n / 2 << endl;
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (n % 2 == 0 && i + j == n + 1) continue;
            if (n % 2 == 1 && i + j == n) continue;
            cout << i << " " << j << endl;
        }
    }

    return 0;
}