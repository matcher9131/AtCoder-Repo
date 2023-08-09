#include <vector>
using namespace std;


template <typename T>
T sum(const vector<T> &vec) {
    T s = 0;
    for (const auto &&i : vec) {
        s += i;
    }
    return s;
}


template <typename T>
T sum(vector<T>::iterator begin, vector<T>::iterator end) {
    T s = 0;
    for (auto it = begin; it != end; ++it) {
        s += *it;
    }
    return s;
}
