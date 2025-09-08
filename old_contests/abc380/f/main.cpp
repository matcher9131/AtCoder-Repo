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

int getSide(int state, int i) {
    return state % (int)pow(3, i);
}

int main() {
    int n, m, l;
    cin >> n >> m >> l;
    int nc = n + m + l;
    vector<int> cards(nc);
    for (int i = 0; i < nc; ++i) {
        cin >> cards[i];
    }
    // 0: 高橋勝ち, 1: 青木勝ち, 2: 未探索
    vector<int> states(2 * (int)pow(3, nc), 2);
    int ns = (int)pow(3, nc);
    auto getSide = [](int state, int i) -> int {
        return (state / (int)pow(3, i)) % 3;
    };
    function<int(int, int)> search = [&](int cardsState, int turn) -> bool {
        int boardState = cardsState + turn * ns;
        // 探索済
        if (states[boardState] != 2) {
            return states[boardState] == turn;
        }

        for (int i = 0; i < nc; ++i) {
            if (getSide(cardsState, i) != turn) continue;
            // i枚目のカードを場に出す
            int newState = cardsState + (2 - turn) * (int)pow(3, i);
            for (int j = 0; j < nc; ++j) {
                if (getSide(newState, j) == 2 && cards[j] < cards[i]) {
                    if (cards[j] >= cards[i]) continue;
                    // j枚目のカードをもらう
                    int newState2 = newState + (turn - 2) * (int)pow(3, j);
                    // 相手が負けになるもらい方があれば自分が必勝
                    if (!search(newState2, !turn)) return true;
                }
            }
            // カードを出すがもらわない局面
            if (!search(newState, !turn)) return true;
        }

        // 出せるカードがない→相手が勝ち
        states[boardState] = !turn;
        return false;
    };

    int initialState = ([&](){
        int cs = 0;
        int i = n;
        for (; i < n + m; ++i) {
            cs += (int)pow(3, i);
        }
        for (; i < nc; ++i) {
            cs += 2 * (int)pow(3, i);
        }
        return cs;
    })();

    cout << (search(initialState, 0) ? "Takahashi" : "Aoki") << endl;

    return 0;
}