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
    int q;
    cin >> q;
    unordered_map<int, int> map;

    while (q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            ++map[x];
        } else if (k == 2) {
            int x;
            cin >> x;
            --map[x];
            if (map[x] == 0) map.erase(x);
        } else {
            cout << map.size() << endl;
        }
    }

    return 0;
}