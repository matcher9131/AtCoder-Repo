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
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    if (n > 1) {
        int answer = *max_element(p.begin() + 1, p.end()) - p[0];
        cout << (answer >= 0 ? answer + 1 : 0) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
