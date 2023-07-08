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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;


int main() {
    int a, b;
    cin >> a >> b;

    cout << (a % 3 != 0 && b == a + 1 ? "Yes" : "No") << endl;

    return 0;
}