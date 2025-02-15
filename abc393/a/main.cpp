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
    string s1, s2;
    cin >> s1 >> s2;

    if (s1 == "sick") {
        if (s2 == "sick") {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    } else if (s2 == "sick") {
        cout << 3 << endl;
    } else {
        cout << 4 << endl;
    }

    return 0;
}