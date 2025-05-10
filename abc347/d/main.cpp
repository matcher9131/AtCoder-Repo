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


int main() {
    int a, b;
    ull c;
    cin >> a >> b >> c;

    int cc = popcount(c);
    int abMax = a + b <= 60 ? a + b : 120 - a - b;
    if (abMax < cc || (a + b) % 2 != cc % 2) {
        cout << -1 << endl;
        return 0;
    }

    int z = (a + b - cc) / 2;
    ull x = 0, y = 0;
    int ai = 0, bi = 0;
    for (int ci = 0; ci < 60; ++ci) {
        if (c & (1ULL << ci)) {
            if (ai < a - z) {
                x |= 1ULL << ci;
                ++ai;
            } else if (bi < b - z) {
                y |= 1ULL << ci;
                ++bi;
            }
        }
    }
    if (ai < a - z || bi < b - z || (x | y) != c) {
        cout << -1 << endl;
        return 0;
    }

    int zi = 0;
    for (int ci = 0; ci < 60; ++ci) {
        if (zi < z && ((x | y) & (1ULL << ci)) == 0) {
            x |= 1ULL << ci;
            y |= 1ULL << ci;
            ++zi;
        }
    }
    if (zi < z) {
        cout << -1 << endl;
        return 0;
    }

    cout << x << " " << y << endl;
    return 0;
}