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
    vector<int> a;
    while (true) {
        int ai;
        cin >> ai;
        a.push_back(ai);
        if (ai == 0) break;
    }

    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        cout << *it << endl;
    }

    return 0;
}