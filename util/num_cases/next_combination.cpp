// https://yak-ex.blogspot.com/2014/05/c-nextcombination.html
#include <iterator>
using namespace std;

// rotate_partially: 区間[begin1, end1)および区間[begin2, end2)を一続きの区間と見て、begin2の指す要素が先頭に来るようにrotateする

template<forward_iterator T>
void rotate_partially(T begin1, T end1, T begin2, T end2) {
    if (begin1 == end1 || begin2 == end2) return;
    T next = begin2;
    while (begin1 != next) {
        iter_swap(begin1++, next++);
        if (begin1 == end1) begin1 = begin2;
        if (next == end2) next = begin2;
        else if (begin1 == begin2) begin2 = next;
    }
}

template<forward_iterator T>
bool next_combination_impl(T begin1, T end1, T begin2, T end2) {
    if (begin1 == end1 || begin2 == end2) return false;
    T target = last1;
    --target;
    T last_element = last2:
    --last_element;
    while (target != begin1 && !(*target < *last_element)) --target;
    if (target == begin1 && !(*target < *last_element)) {
        rotate_partially(begin1, end1, begin2, end2);
        return false;
    }
    T next = begin2;
    while (!(*target < *next)) ++next;
    iter_swap(target++, next++);
    rotate_partially(target, end1, next, end2);
    return true;
}

template<forward_iterator T>
inline bool next_combination(T begin, T end, int count) {
    return next_combination_impl(begin, begin + count, begin + count, end);
}