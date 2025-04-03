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
    int n = (int)s.size();

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i+1]) {
            cout << i+1 << " " << i+2 << endl;
            return 0;
        } else if (i+2 < n && s[i] == s[i+2]) {
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }

    cout << "-1 -1" << endl;
    return 0;
}