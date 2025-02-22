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

    vector<int> next(n), prev(n);
    int numDeleted = 0;
    for (int i = 0; i < n; ++i) {
        next[i] = i + 1;
        prev[i] = i - 1;
    }

    auto isBlankBracket = [&](int i) -> bool {
        return next[i] < n && ((s[i] == '(' && s[next[i]] == ')') || (s[i] == '[' && s[next[i]] == ']') || (s[i] == '<' && s[next[i]] == '>'));
    };

    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < n - 1; ++i) {
        if (isBlankBracket(i)) {
            que.emplace(i);
        }
    }
    while (!que.empty()) {
        int i = que.top();
        que.pop();
        int j = next[i];
        numDeleted += 2;
        int p = prev[i];
        int nx = next[j];
        if (nx < n) prev[nx] = p;
        if (p >= 0) next[p] = nx;
        if (p >= 0 && isBlankBracket(p)) que.emplace(p);
    }

    cout << (numDeleted == n ? "Yes" : "No") << endl;

    return 0;
}