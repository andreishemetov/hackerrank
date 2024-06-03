//
//  producerConsumerProblem.cpp
//  hackerrank
//
//  Created by Andrei Shemetau on 03/06/2024.
//

#include "producerConsumerProblem.hpp"
#include <iostream> // Include for input/output operations
#include <queue> // Include for using the queue data structure
#include <thread> // Include for using thread functionality
#include <mutex> // Include for using mutex for synchronization
#include <condition_variable> // Include for using condition variables
#include <semaphore>


// https://medium.com/nerd-for-tech/hands-on-multithreading-with-c-04-producer-consumer-problem-26abdddc485d

std::mutex mtx; // Mutex for synchronization
std::condition_variable cond_var; // Condition variable for producer-consumer signaling
std::queue<int> buffer; // Queue to act as a buffer
const unsigned int MAX_BUFFER_SIZE = 5; // Maximum size of the buffer

void producer(int value) {
    std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
    cond_var.wait(lock, [] { return buffer.size() < MAX_BUFFER_SIZE; }); // Wait until there's space in buffer
    buffer.push(value); // Add value to the buffer
    std::cout << "Producing " << value << std::endl; // Output the produced value
    std::cout << "Buffer size after producing: " << buffer.size() << std::endl << std::endl; // Display buffer size after producing
    lock.unlock(); // Unlock the mutex
    cond_var.notify_one(); // Notify one waiting thread
}

void consumer() {
    std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
    cond_var.wait(lock, [] { return buffer.size() > 0; }); // Wait until there's something in the buffer
    int value = buffer.front(); // Get the front value from buffer
    buffer.pop(); // Remove the value from buffer
    std::cout << "Consuming " << value << std::endl; // Output the consumed value
    std::cout << "Buffer size after consuming: " << buffer.size() << std::endl << std::endl; // Display buffer size after consuming
    lock.unlock(); // Unlock the mutex
    cond_var.notify_one(); // Notify one waiting thread
}

void producer_consumer_problem_ex() {
    std::thread producerThread([] {
        for (int i = 1; i <= 20; ++i) {
            producer(i); // Create a thread to produce values
        }
    });
    // Delay before starting consumer thread
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::thread consumerThread([] {
        for (int i = 1; i <= 20; ++i) {
            consumer(); // Create a thread to consume values
        }
    });
    producerThread.join(); // Wait for producer thread to finish
    consumerThread.join(); // Wait for consumer thread to finish
    return;
}

std::counting_semaphore<MAX_BUFFER_SIZE> semaphoreFull(0);
std::counting_semaphore<MAX_BUFFER_SIZE> semaphoreEmpty(MAX_BUFFER_SIZE);

void producer1(int value) {
    semaphoreEmpty.acquire(); // Wait until there's space in buffer
    std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
    buffer.push(value); // Add value to the buffer
    std::cout << "Producing " << value << std::endl; // Output the produced value
    std::cout << "Buffer size after producing: " << buffer.size() << std::endl << std::endl; // Display buffer size after producing
    lock.unlock(); // Unlock the mutex
    semaphoreFull.release();
}

void consumer1() {
    semaphoreFull.acquire();
    std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
    int value = buffer.front(); // Get the front value from buffer
    buffer.pop(); // Remove the value from buffer
    std::cout << "Consuming " << value << std::endl; // Output the consumed value
    std::cout << "Buffer size after consuming: " << buffer.size() << std::endl << std::endl; // Display buffer size after consuming
    lock.unlock(); // Unlock the mutex
    semaphoreEmpty.release();
}

void producer_consumer_problem_with_semaphore_ex() {
    std::thread producerThread([] {
        for (int i = 1; i <= 20; ++i) {
            producer1(i); // Create a thread to produce values
        }
    });
    // Delay before starting consumer thread
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::thread consumerThread([] {
        for (int i = 1; i <= 20; ++i) {
            consumer1(); // Create a thread to consume values
        }
    });
    producerThread.join(); // Wait for producer thread to finish
    consumerThread.join(); // Wait for consumer thread to finish
    return;
}
