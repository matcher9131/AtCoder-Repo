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
    ll h;
    cin >> h;

    ll t = 0;
    for (int i = 0; ; ++i) {
        t += 1LL << i;
        if (t > h) {
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}