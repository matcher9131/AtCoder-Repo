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
    int n = s.size();

    if (s[0] != '<' || s[n-1] != '>') {
        cout << "No" << endl;
        return 0;
    }

    cout << (all_of(s.begin() + 1, s.end() - 1, [](char c) { return c == '='; }) ? "Yes" : "No") << endl;

    return 0;
}