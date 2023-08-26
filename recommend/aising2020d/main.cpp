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

int n;
int ln;
string x;

int popcount(int i) {
    int pc = 0;
    for (int j = 0; j < ln; ++j) {
        if (i & 1 << j) ++pc;
    }
    return pc;
}

void pc0() {
    for (int i = 0; i < n; ++i) {
        cout << 1 << endl;
    }
}

int main() {
    cin >> n >> x;
    ln = (int)ceil(log2(n)) + 1;
    int pc = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] == '1') ++pc;
    }

    if (pc == 0) {
        pc0();
        return 0;
    }

    // table[i] = i % popcount(i)
    vector<int> table(n + 1);
    for (int i = 1; i <= n; ++i) {
        int pc = popcount(i);
        table[i] = i % pc;
    }

    // 2^iをpcp1, pcm1で割った余り
    vector<int> pcp1r(n), pcm1r(n);
    pcp1r[0] = 1;
    pcm1r[0] = 1;
    for (int i = 1; i < n; ++i) {
        pcp1r[i] = 2 * pcp1r[i - 1] % (pc + 1);
    }
    if (pc > 1) {
        for (int i = 1; i < n; ++i) {
            pcm1r[i] = 2 * pcm1r[i - 1] % (pc - 1);
        }
    }

    int pcp1r0 = 0, pcm1r0 = 0;
    for (int i = 0; i < n; ++i) {
        if (x[n - 1 - i] == '1') {
            pcp1r0 += pcp1r[i];
            pcp1r0 %= pc + 1;
        }
    }
    if (pc > 1) {
        for (int i = 0; i < n; ++i) {
            if (x[n - 1 - i] == '1') {
                pcm1r0 += pcm1r[i];
                pcm1r0 %= pc - 1;
            }
        }
    }

    if (pc > 1) {
        for (int i = 0; i < n; ++i) {
            int j = x[i] == '0' ? (pcp1r0 + pcp1r[n - 1 - i]) % (pc + 1) : (pcm1r0 - pcm1r[n - 1 - i] + pc - 1) % (pc - 1);
            int c = 1;
            while (j > 0) {
                j = table[j];
                ++c;
            }
            cout << c << endl;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (x[i] == '1') {
                cout << 0 << endl;
                continue;
            }
            int j = (pcp1r0 + pcp1r[n - 1 - i]) % (pc + 1);
            int c = 1;
            while (j > 0) {
                j = table[j];
                ++c;
            }
            cout << c << endl;
        }
    }
    

    return 0;
}