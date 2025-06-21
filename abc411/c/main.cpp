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
    int n, nq;
    cin >> n >> nq;

    vector<bool> isBlack(n+1);
    set<int> boundary;
    while (nq--) {
        int ai;
        cin >> ai;

        isBlack[ai] = !isBlack[ai];
        boundary.erase(ai-1);
        boundary.erase(ai);
        if (isBlack[ai-1] != isBlack[ai]) boundary.insert(ai-1);
        if (isBlack[ai] != isBlack[ai+1]) boundary.insert(ai);

        cout << (int)boundary.size() / 2 << endl;
    }

    return 0;
}