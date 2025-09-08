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
    cin >> n;

    for (int x = 0; x <= n; ++x) {
        for (int y = 0; x + y <= n; ++y) {
            for (int z = 0; x + y + z <= n; ++z) {
                cout << x << " " << y << " " << z << endl;
            }
        }
    }

    return 0;
}