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
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        int pi;
        cin >> pi;
        --pi;
        order[pi] = i;
    }
    int nq;
    cin >> nq;
    while (nq--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        cout << (order[a] < order[b] ? a+1 : b+1) << endl;
    }

    return 0;
}