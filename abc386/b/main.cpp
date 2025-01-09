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

    int skip = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0' && i + 1 < s.length() && s[i + 1] == '0') {
            ++i;
            ++skip;
        }
    }

    cout << s.length() - skip << endl;
    return 0;
}