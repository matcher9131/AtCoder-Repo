#include <algorithm>
#include <functional>
using namespace std;

extern int INITIAL_NG;
extern int INITIAL_OK;
extern bool isOK(int);


function<int()> binary_search = [&]() {
    int ng = INITIAL_NG;
    int ok = INITIAL_OK;

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
};