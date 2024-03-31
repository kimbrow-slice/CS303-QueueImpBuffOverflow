#include "vulnQueue.h"
#include <vector>

namespace JK {

    // Function to display the contents of the queue
    void vulnQueue::display() const {
        for (int i = 0; i < count; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Fucntion to empty the queue
    bool vulnQueue::empty() const {
        return count == 0;
    }

    //  Function to pop an element from the queue 
    void vulnQueue::pop() {
        if (count <= 0) {
            std::cerr << "The queue is empty, cannot pop any elements." << std::endl;
            return;
        }
        for (int i = 1; i < count; ++i) {
            data[i - 1] = data[i];
        }
        --count;
    }
    
    // Function to move the front element to the back of the queue
    void JK::vulnQueue::move_to_rear() {
        if (empty()) {
            std::cout << "The queue is empty, cannot move any element to the rear." << std::endl;
            return;
        }
        // Store the first element
        int frontElement = data[0];
        // Shift all elements to the left
        for (int i = 1; i < count; ++i) {
            data[i - 1] = data[i];
        }
        // Place the first element at the end
        data[count - 1] = frontElement;
        data[count - 1] = frontElement;
    }
    // Function to push a new element into the queue
    void vulnQueue::push(int val) {
        // Intentionally not checking if the queue is full to allow integer overflow
        data[count++] = val;
        std::cout << "Pushing value: " << val << std::endl;
    }

    // Function to find the front element of the queue
    int JK::vulnQueue::front() const {
        if (empty()) {
            throw std::runtime_error("The queue is empty, cannot retrieve the front element.");
        }
        return data[0]; // Assuming data is the array storing queue elements
    }

}
