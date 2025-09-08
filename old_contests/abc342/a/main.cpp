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

    if (s[0] != s[1] && s[1] == s[2]) {
        cout << 1 << endl;
        return 0;
    }

    char major = s[0];
    for (int i = 1; i < (int)s.size(); ++i) {
        if (s[i] != major) {
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}