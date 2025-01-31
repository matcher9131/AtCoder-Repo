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
    string s, t;
    cin >> s >> t;

    int n = s.size();
    queue<int> que;
    for (int i = 0; i < n; ++i) {
        if (s[i] > t[i]) que.push(i);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] < t[i]) que.push(i);
    }

    cout << que.size() << endl;
    while (!que.empty()) {
        int i = que.front();
        que.pop();
        s[i] = t[i];
        cout << s << endl;
    }

    return 0;
}