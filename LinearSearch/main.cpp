#include <vector>
#include <iostream>
using namespace std;

template<typename Item_Type>
int linear_search_last(vector<Item_Type>& items, Item_Type& target, size_t pos_first) {

    // If pos_first is beyond the last index, return -1 indicating not found.
    if (pos_first == items.size()) {
        return -1;
    }

    // Search in the rest of the vector.
    int index_in_rest = linear_search_last(items, target, pos_first + 1);

    // If target is found in the rest of the vector, return that index.
    if (index_in_rest != -1) {
        return index_in_rest;
    }

    // Otherwise, check the current position. If match, return current index; else, propagate not found (-1).
    if (target == items[pos_first]) {
        return pos_first;
    }
    else {
        return -1;
    }
}

// Given example for testing
int main() {
    vector<int> vec = { 1, 2, 3, 4, 5, 3, 2 };
    int target = 3;
    int last_index = linear_search_last(vec, target, 0);
    cout << "The last occurrence of " << target << " is at index: " << last_index << endl;
    return 0;
}

