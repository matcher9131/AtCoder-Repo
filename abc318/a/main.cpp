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
using namespace std;
using ll = long long;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    int answer = 0;
    int i = m;
    while (true) {
        if (i > n) break;
        ++answer;
        i += p;
    }

    cout << answer << endl;

    return 0;
}
