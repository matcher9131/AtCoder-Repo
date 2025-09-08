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
    int n;
    char c1, c2;
    string s;
    cin >> n >> c1 >> c2 >> s;

    for (int i = 0; i < n; ++i) {
        if (s[i] != c1) {
            s[i] = c2;
        }
    }

    cout << s << endl;

    return 0;
}