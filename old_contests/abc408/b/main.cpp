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
    set<int> a;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        a.insert(ai);
    }

    cout << a.size() << endl;
    for (auto it = a.begin(); it != a.end(); ++it) {
        cout << (it != a.begin() ? " " : "") << *it;
    }
    cout << endl;

    return 0;
}