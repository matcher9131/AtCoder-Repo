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

    queue<int> que;
    while (nq--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            que.push(x);
        } else {
            int x = que.front();
            que.pop();
            cout << x << endl;
        }
    }

    return 0;
}