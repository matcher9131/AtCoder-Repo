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
    vector<int> v(4);
    for (int i = 0; i < 4; ++i) {
        int ai;
        cin >> ai;
        --ai;
        ++v[ai];
    }

    int r = 0;
    for (int i = 0; i < 4; ++i) {
        r += v[i] % 2;
    }

    cout << (4 - r) / 2 << endl;

    return 0;
}