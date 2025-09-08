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
    vector<string> s{ "tourist", "ksun48", "Benq", "Um_nik", "apiad", "Stonefeang", "ecnerwala", "mnbvmar", "newbiedmy", "semiexp" };
    vector<int> r{ 3858, 3679, 3658, 3648, 3638, 3630, 3613, 3555, 3516, 3481 };
    string si;
    cin >> si;
    for (int i = 0; i < 10; ++i) {
        if (s[i] == si) cout << r[i] << endl;
    }

    return 0;
}