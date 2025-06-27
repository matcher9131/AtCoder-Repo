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
    vector<int> next(n);
    int start = -1;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        --ai;
        if (ai >= 0) {
            next[ai] = i;
        } else {
            start = i;
        }
    }

    int current = start;
    for (int i = 0; i < n; ++i) {
        cout << current+1 << " \n"[i == n - 1];
        current = next[current];
    }

    return 0;
}