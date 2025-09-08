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

    vector<int> ch(26);
    for (const char c : s) {
        ++ch[c - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
        if (ch[i] == 0) {
            cout << (char)('a' + i) << endl;
            return 0;
        }
    }

    return 0;
}