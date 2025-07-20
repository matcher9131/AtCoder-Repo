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

vector<int> prime{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 93, 97 };
int pn = prime.size();

int main() {
    int n;
    cin >> n;

    vector<int> c(pn);
    for (int i = 2; i <= n; ++i) {
        int t = i;
        for (int pi = 0; pi < pn; ++pi) {
            if (t == 1) break;
            if (t % prime[pi] == 0) {
                ++c[pi];
                t /= prime[pi];
                --pi;
            }
        }
    }

    int answer = 0;
    // 75 = 25 * 3, 15 * 5, 5 * 5 * 3
    for (int pi = 0; pi < pn; ++pi) {
        if (c[pi] >= 74) ++answer;
    }
    for (int pi = 0; pi < pn - 1; ++pi) {
        for (int pj = pi + 1; pj < pn; ++pj) {
            if (c[pi] >= 24 && c[pj] >= 2) ++answer;
            if (c[pi] >= 2 && c[pj] >= 24) ++answer;
            if (c[pi] >= 14 && c[pj] >= 4) ++answer;
            if (c[pi] >= 4 && c[pj] >= 14) ++answer;
        }
    }
    for (int pi = 0; pi < pn - 2; ++pi) {
        for (int pj = pi + 1; pj < pn - 1; ++pj) {
            for (int pk = pj + 1; pk < pn; ++pk) {
                if (c[pi] >= 4 && c[pj] >= 4 && c[pk] >= 2) ++answer;
                if (c[pi] >= 4 && c[pj] >= 2 && c[pk] >= 4) ++answer;
                if (c[pi] >= 2 && c[pj] >= 4 && c[pk] >= 4) ++answer;
            }
        }
    }

    cout << answer << endl;

    // for (int i = 0; i < pn; ++i) {
    //     cout << c[i] << " ";
    // }
    // cout << endl;

    return 0;
}