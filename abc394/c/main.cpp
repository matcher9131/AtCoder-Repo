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
    string s;
    cin >> s;
    int n = s.size();

    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'W' && s[i+1] == 'A') que.emplace(i);
    }
    while (!que.empty()) {
        int i = que.top();
        que.pop();
        s[i] = 'A';
        s[i+1] = 'C';
        if (i > 0 && s[i-1] == 'W') que.emplace(i-1);
    }

    cout << s << endl;

    return 0;
}