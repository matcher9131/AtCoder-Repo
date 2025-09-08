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

    if (s.size() % 2 != 0) {
        cout << "No" << endl;
        return 0;
    }

    vector<bool> chars(26);

    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[2*i] != s[2*i+1]) {
            cout << "No" << endl;
            return 0;
        }
        int c = (int)(s[2*i] - 'a');
        if (chars[c]) {
            cout << "No" << endl;
            return 0;
        }
        chars[c] = true;
    }

    cout << "Yes" << endl;

    return 0;
}