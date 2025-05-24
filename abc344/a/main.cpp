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

    string t = "";
    bool ok = true;
    for (const char ch : s) {
        if (ch == '|') {
            ok = !ok;
        } else if (ok) {
            t += ch;
        }
    }

    cout << t << endl;
    return 0;
}