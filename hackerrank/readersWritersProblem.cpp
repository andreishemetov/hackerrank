//
//  readersWritersProblem.cpp
//  hackerrank
//
//  Created by Andrei Shemetau on 31/05/2024.
//

#include "readersWritersProblem.hpp"
#include <iostream> // Includes standard I/O stream library
#include <thread> // Includes thread library for multi-threading
#include <mutex> // Includes mutex library for synchronization
#include <condition_variable> // Includes condition_variable library for thread waiting
#include <vector> 
#include <random> // Includes the random library for generating random numbers
#include <chrono> // Includes the chrono library for dealing with durations

// https://medium.com/nerd-for-tech/hands-on-multithreading-with-c-05-readers-writers-problem-348a035c268e

using namespace std;

std::mutex resource_mutex; // Mutex for protecting shared resource access
std::mutex reader_count_mutex; // Mutex for protecting reader count variable
int reader_count = 0; // Global variable to keep track of reader count


/*
 ================================================
 Solve readers & writers problem with read priority
 ================================================
 */

void read1(int reader_id) { // Function for reader thread
    {
        std::unique_lock<std::mutex> lock(reader_count_mutex); // Locks reader_count_mutex
        reader_count++; // Increments reader count
        if (reader_count == 1) {
            resource_mutex.lock(); // Locks resource_mutex if first reader
        }
    }
    
    std::cout << "Reader " << reader_id << " is reading." << std::endl; // Outputs reading status
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulates reading operation

    {
        std::unique_lock<std::mutex> lock(reader_count_mutex); // Re-locks reader_count_mutex
        std::cout << "Reader " << reader_id << " has finished reading." << std::endl; // Outputs finished reading status
        reader_count--; // Decrements reader count
        if (reader_count == 0) {
            resource_mutex.unlock(); // Unlocks resource_mutex if last reader
        }
    }
}

void write1(int writer_id) { // Function for writer thread
    resource_mutex.lock(); // Locks resource_mutex
    std::cout << "Writer " << writer_id << " is writing." << std::endl; // Outputs writing status
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulates writing operation
    std::cout << "Writer " << writer_id << " has finished writing." << std::endl; // Outputs finished writing status
    resource_mutex.unlock(); // Unlocks resource_mutex
}

void readers_writers_read_priority_ex() { // Main function
    std::vector<std::thread> readers; // Vector to store reader threads
    std::vector<std::thread> writers; // Vector to store writer threads

    for (int i = 1; i <= 5; ++i) { // Loops to create 5 readers and 5 writers
        readers.push_back(std::thread(read1, i)); // Starts reader thread
        writers.push_back(std::thread(write1, i)); // Starts writer thread
    }

    for (auto& t : readers) t.join(); // Waits for all reader threads to finish
    for (auto& t : writers) t.join(); // Waits for all writer threads to finish

    return; // Ends the program
}


/*
 ================================================
 Solve readers & writers problem with write priority
 ================================================
 */

std::condition_variable reader_cv; // Condition variables for readers
std::condition_variable writer_cv; // Condition variables for writers
int writer_count = 0; // Counters for the number of writers
bool writer_waiting = false; // Flag to indicate if a writer is waiting

std::random_device rd; // Random device to seed the generator
std::mt19937 gen(rd()); // Mersenne Twister generator
std::uniform_int_distribution<> dis(100, 500); // Uniform distribution for random sleep duration

void read(int reader_id) { // Function for reader threads
    {
        std::unique_lock<std::mutex> lock(reader_count_mutex); // Acquire lock for reader count
        reader_cv.wait(lock, [] { return !writer_waiting; }); // Wait until no writer is waiting

        reader_count++; // Increment reader count
        if (reader_count == 1) {
            resource_mutex.lock(); // Lock resource if first reader
        }

        std::cout << "Reader " << reader_id << " is reading." << std::endl; // Print reading message
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(dis(gen))); // Simulate reading by sleeping

    {
        std::unique_lock<std::mutex> lock(reader_count_mutex); // Re-acquire lock for reader count
        std::cout << "Reader " << reader_id << " has finished reading." << std::endl; // Print finished reading message
        reader_count--; // Decrement reader count
        if (reader_count == 0) {
            resource_mutex.unlock(); // Unlock resource if last reader
            writer_cv.notify_one(); // Notify one writer if any
        }
    }
}

void write(int writer_id) { // Function for writer threads
    {
        std::unique_lock<std::mutex> lock(reader_count_mutex); // Acquire lock for writer count
        writer_count++; // Increment writer count
        writer_waiting = true; // Set writer waiting flag

        writer_cv.wait(lock, [] { return reader_count == 0; }); // Wait until no readers are present
        resource_mutex.lock(); // Lock resource for writing

        std::cout << "Writer " << writer_id << " is writing." << std::endl; // Print writing message
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(dis(gen))); // Simulate writing by sleeping

    {
        std::unique_lock<std::mutex> lock(reader_count_mutex); // Re-acquire lock for writer count
        std::cout << "Writer " << writer_id << " has finished writing." << std::endl; // Print finished writing message
        writer_count--; // Decrement writer count
        writer_waiting = writer_count > 0; // Update writer waiting flag
        resource_mutex.unlock(); // Unlock resource after writing
        if (writer_waiting) {
            writer_cv.notify_one(); // Notify next writer if any
        } else {
            reader_cv.notify_all(); // Notify all readers if no writers
        }
    }
}

void readers_writers_write_priority_ex() { // Main function
    std::vector<std::thread> readers; // Vector to store reader threads
    std::vector<std::thread> writers; // Vector to store writer threads

    for (int i = 1; i <= 5; ++i) { // Create and start 5 reader and writer threads
        readers.push_back(std::thread(read, i)); // Start reader thread
        writers.push_back(std::thread(write, i)); // Start writer thread
    }

    for (auto& t : readers) t.join(); // Wait for all reader threads to finish
    for (auto& t : writers) t.join(); // Wait for all writer threads to finish

    return; // End of program
}

