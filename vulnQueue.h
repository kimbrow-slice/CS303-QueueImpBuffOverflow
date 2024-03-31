#ifndef VULNQUEUE_H
#define VULNQUEUE_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>

namespace JK {
    
    class vulnQueue {
        static const int QUEUE_SIZE = 10;
        int data[QUEUE_SIZE];
        int count = 0;
        bool initialValuesEntered = false;

    public:
        vulnQueue() : data{} {} // Initialize data array to all zeros

        int getQueueSize() const {
            return QUEUE_SIZE;
        }
        int size() const {
            return count;
        }
        void move_to_rear();
        void push(int val);
        int front() const;
        void pop();
        bool empty() const;
        void display() const;
    };

}

#endif // VULNQUEUE_H
