#include <vector>
#include <iostream>

// Defines the insertion sort function that sorts a vector of integers in ascending order.
void insertion_sort(std::vector<int>& num) {
    // Check if the vector is empty. If it is, return immediately as there's nothing to sort.
    if (num.empty()) return;

    // Start from the second element and iterate through the vector.
    for (std::size_t j = 1; j < num.size(); ++j) {
        int key = num[j];
        int i = j - 1;

        // Move through the sorted portion of the vector from right to left until the correct position for the key is found.
        while (i >= 0 && num[i] > key) {
            // Shift the larger element to the right to make space for the key.
            num[i + 1] = num[i];
            --i; // Move to the previous element in the sorted portion.
        }
        // Insert the key in its correct position in the sorted portion of the vector.
        num[i + 1] = key;
    }
}

// Given examplefor testing
int main() {
    
    std::vector<int> numbers = { 5, 3, 1, 4, 6 };
    insertion_sort(numbers);

    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
