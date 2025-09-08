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
    vector<int> pos(26);
    for (int i = 0; i < s.size(); ++i) {
        pos[s[i] - 'A'] = i;
    }

    int ans = 0;
    for (int i = 1; i < 26; ++i) {
        ans += abs(pos[i] - pos[i - 1]);
    }

    cout << ans << endl;

    return 0;
}