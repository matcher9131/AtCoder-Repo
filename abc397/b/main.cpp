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

    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0 && s[i] == 'o') {
            s.insert(s.begin() + i, 'i');
            ++ans;
        } else if (i % 2 == 1 && s[i] == 'i') {
            s.insert(s.begin() + i, 'o');
            ++ans;
        }
    }
    if (s.back() == 'i') ++ans;

    cout << ans << endl;
    return 0;
}