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

int ha, wa, hb, wb, hc, wc;
vector<string> a, b, c;
int al, ar, au, ab, bl, br, bu, bb;

bool canCreate(int auli, int aulj, int buli, int bulj) {
    for (int i = 0; i < hc; ++i) {
        for (int j = 0; j < wc; ++j) {
            int ai = i - auli;
            int aj = j - aulj;
            int bi = i - buli;
            int bj = j - bulj;
            bool aIsBlack = ai >= 0 && ai < ha && aj >= 0 && aj < wa && a[ai][aj] == '#';
            bool bIsBlack = bi >= 0 && bi < hb && bj >= 0 && bj < wb && b[bi][bj] == '#';
            if (c[i][j] == '#') {
                if (!aIsBlack && !bIsBlack) return false;
            } else {
                if (aIsBlack || bIsBlack) return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> ha >> wa;
    a = vector<string>(ha);
    al = wa, ar = 0, au = ha, ab = 0;
    for (int i = 0; i < ha; ++i) {
        cin >> a[i];
    }

    cin >> hb >> wb;
    b = vector<string>(hb);
    bl = wb, br = 0, bu = hb, bb = 0;
    for (int i = 0; i < hb; ++i) {
        cin >> b[i];
    }

    cin >> hc >> wc;
    c = vector<string>(hc);
    for (int i = 0; i < hc; ++i) {
        cin >> c[i];
    }

    for (int i = 0; i < ha; ++i) {
        for (int j = 0; j < wa; ++j) {
            if (a[i][j] == '#') {
                al = min(al, j);
                ar = max(ar, j);
                au = min(au, i);
                ab = max(ab, i);
            }
        }
    }

    for (int i = 0; i < hb; ++i) {
        for (int j = 0; j < wb; ++j) {
            if (b[i][j] == '#') {
                bl = min(bl, j);
                br = max(br, j);
                bu = min(bu, i);
                bb = max(bb, i);
            }
        }
    }

    for (int auli = -au; auli < hc - ab; ++auli) {
        for (int aulj = -al; aulj < wc - ar; ++aulj) {
            for (int buli = -bu; buli < hc - bb; ++buli) {
                for (int bulj = -bl; bulj < wc - br; ++bulj) {
                    if (canCreate(auli, aulj, buli, bulj)) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}