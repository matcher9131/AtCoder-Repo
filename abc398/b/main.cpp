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
    vector<int> c(13);
    for (int i = 0; i < 7; ++i) {
        int ai;
        cin >> ai;
        --ai;
        ++c[ai];
    }
    sort(c.begin(), c.end(), greater<int>());
    
    cout << (c[0] >= 3 && c[1] >= 2 ? "Yes" : "No") << endl;

    return 0;
}