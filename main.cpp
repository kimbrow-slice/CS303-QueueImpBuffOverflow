#include "vulnQueue.h"
#include <iostream>
#include <limits>

int main() {
    JK::vulnQueue queue;
    int value;

    std::cout << "Welcome to Queue Operations Menu\n";
    std::cout << "Initially, please push 10 positive integer values into the queue:\n";
    std::cout << "WARNING: The queue is statically casted to a size of 10.\nThis was intentially done to allow the demonstration of an integer overflow with unsecure code.\n";
    for (int i = 0; i < 10; ) {
        std::cout << "Enter an integer value (0 or positive) to push: ";
        if (std::cin >> value) {
            if (value >= 0) { 
                queue.push(value);
                ++i; // Increment only if the input was valid
            }
            else {
                std::cout << "Your input was invalid! : Please enter an integer value that is 0 or positive.\n";
            }
        }
        else {
            std::cout << "Your input was invalid! : Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }      
    }
    std::cout << "The queue is now full!\n";

    // Main loop for the queue operations
    while (true) {
        bool validInput = false;
        int choice = -1;

        // Loop until we have valid input.
        while (!validInput) {
            // Display the UI
            
            std::cout << "\nSelect operation:\n";
            std::cout << "0. Exit the program\n";
            std::cout << "1. Push (If you would like to test this function try popping or clearing first)\n";
            std::cout << "2. Pop\n";
            std::cout << "3. Check if the queue is empty\n";
            std::cout << "4. Display front\n";
            std::cout << "5. Display the queue\n";
            std::cout << "6. Move front element to rear\n";
            std::cout << "7. Clear the queue\n";
            std::cout << "Enter your choice (0-7): ";

            // Input validation for choice
            if (std::cin >> choice) {
                if (choice >= 0 && choice <= 7) {
                    validInput = true; // If the input is valid, then proceed with processing
                }
                else {
                    // Inform user an error has occured.
                    std::cout << "Your input was invalid! Please enter a number between 0 and 7.\n";
                }
            }
            else {
                std::cout << "Your input was invalid! . Please enter a numeric value.\n";
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            }
        }
        // Valid user input processing
        switch (choice) {
        case 0:
            std::cout << "You are exiting the program now! Thanks!\n";
            return 0;
        case 1: {
            long long longValue;
            std::cout << "Enter a positive integer value to push: ";
            while (!(std::cin >> longValue) || longValue <= 0) {
                std::cout << "Invalid input: Please enter a positive integer.\n";
                std::cin.clear(); // Clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the input buffer
                std::cout << "Enter a positive integer value to push: ";
            }

            // Check for integer overflow potential and inform the user
            if (longValue > std::numeric_limits<int>::max() || longValue < std::numeric_limits<int>::min()) {
                std::cout << "Warning: The value you entered may cause integer overflow.\n";
            }
            else {
                std::cout << "You have successfully pushed a new value to the queue!\n";
            }

            int valueToPush = static_cast<int>(longValue); // Cast long long to int, demonstrating overflow if it occurs
            queue.push(valueToPush); // Push the value onto the queue
            std::cout << "Value pushed: " << valueToPush << "\n";
            queue.display(); // Display the current state of the queue
            break;
        }

        case 2:
            // Logic for option to pop value
            if (!queue.empty()) {
                int poppedValue = queue.front(); // Save the front value before popping
                queue.pop();
                std::cout << "You have popped the value: " << poppedValue << "\n";
            }
            else {
                std::cout << "The queue is currently empty. Try adding some values to test this function.\n";
            }
            break;
        case 3:
            // Logic for option to check if the queue is empty
            std::cout << (queue.empty() ? "The queue is empty.\n" : "The queue is not empty.\n");
            break;
        case 4:
            // Logic for option to check for the front element in the queue
            if (!queue.empty()) {
                std::cout << "Front value of the queue: " << queue.front() << "\n";
            }
            else {
                std::cout << "The queue is currently empty. Add some values to find the front!.\n";
            }
            break;
        case 5:
            // Logic for to display the contents to the user
            std::cout << "The queues current contents: ";
            queue.display();
            break;
        case 6: // Logic for moving to the front
            queue.move_to_rear();
            std::cout << "Moved the front element to the rear of the queue.\n";
            break;
        case 7:
            // Logic to clear the queue
            queue = JK::vulnQueue(); // Reinitialize the queue to clear it
            std::cout << "The queue has been cleared!\n";
            break;
        }
    }
}
