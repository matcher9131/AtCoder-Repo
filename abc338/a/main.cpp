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

    if (s[0] < 'A' || 'Z' < s[0]) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i < (int)s.size(); ++i) {
        if (s[i] < 'a' || 'z' < s[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}