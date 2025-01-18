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
    int a = n / 100, b = n / 10 % 10, c = n % 10;

    cout << (100 * b + 10 * c + a) << " " << (100 * c + 10 * a + b) << endl;

    return 0;
}