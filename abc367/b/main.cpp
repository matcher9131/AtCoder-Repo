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
    string x;
    cin >> x;

    for (int i = x.size() - 1; i >= 0; --i) {
        if (x[i] != '0') {
            x = x.substr(0, i + 1);
            break;
        }
    }

    if (x.ends_with('.')) {
        x = x.substr(0, x.size() - 1);
    }

    cout << x << endl;

    return 0;
}