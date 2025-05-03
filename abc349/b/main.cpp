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

    vector<int> count(26);
    for (const char c : s) {
        ++count[c - 'a'];
    }

    map<int, vector<int>> countMap;
    for (int i = 0; i < 26; ++i) {
        if (count[i] > 0) {
            countMap[count[i]].push_back(i);
        }
    }

    bool ans = all_of(countMap.begin(), countMap.end(), [](auto &p) { return p.second.size() == 0 || p.second.size() == 2; });

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}