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
    int nq;
    cin >> nq;
    stack<int> s;
    for (int i = 0; i < 100; ++i) {
        s.push(0);
    }

    while (nq--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            s.push(x);
        } else {
            int ans = s.top();
            s.pop();
            cout << ans << endl;
        }
    }

    return 0;
}