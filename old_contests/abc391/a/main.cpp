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
    string d;
    cin >> d;

    for (int i = 0; i < d.size(); ++i) {
        switch (d[i]) {
            case 'N': cout << "S"; break;
            case 'S': cout << "N"; break;
            case 'E': cout << "W"; break;
            case 'W': cout << "E"; break;
            default: break;
        }
    }
    cout << endl;

    return 0;
}