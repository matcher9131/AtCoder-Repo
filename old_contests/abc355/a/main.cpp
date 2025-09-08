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
    int a, b;
    cin >> a >> b;
    --a;
    --b;

    if (a == b) {
        cout << -1 << endl;
    } else {
        vector<bool> n(3);
        n[a] = true;
        n[b] = true;
        cout << (find(n.begin(), n.end(), false) - n.begin()) + 1 << endl;
    }

    return 0;
}