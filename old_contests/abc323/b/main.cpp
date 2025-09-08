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

void display(const vector<pair<int, int>>& v) {
    if (!v.empty()) cout << v[0].second + 1;
    for (int i = 1; i < v.size(); ++i) {
        cout << " " << v[i].second + 1;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> lose(n);
    for (int i = 0; i < n; ++i) {
        lose[i].second = i;
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == 'x') ++lose[i].first;
        }
    }
    sort(lose.begin(), lose.end(), greater<pair<int, int>>());
    reverse(lose.begin(), lose.end());

    display(lose);

    return 0;
}