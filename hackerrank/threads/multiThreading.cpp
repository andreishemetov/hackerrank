//
//  multiThreading.cpp
//  hackerrank
//
//  Created by Andrei Shemetau on 31/05/2024.
//

#include "multiThreading.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <curl/curl.h>
//#include <nlohmann/json.hpp>

//https://medium.com/nerd-for-tech/hands-on-multithreading-with-c-01-overview-e29087ebeadb

using namespace std;

void func1(){
    for (int i=0; i<200; i++) {
        cout<<"A";
//        this_thread::sleep_for(chrono::milliseconds(1));
    }
}

void func2(){
    for (int i=0; i<200; i++) {
    cout<<"B";
//        this_thread::sleep_for(chrono::milliseconds(1));
    }
}

void runA(string threadName) {
  for (int i = 0; i < 10; i++) {
    string out = threadName + to_string(i) + "\n";
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << out;
  }
}

void runB(string threadName) {
  for (int i = 100; i < 110; i++) {
    string out = threadName + to_string(i) + "\n";
    this_thread::sleep_for(chrono::milliseconds(2));
    cout << out;
  }
}

void execute(){
//    thread worker1(func1);
//    thread worker2(func2);
    
    thread tA(runA, "A");
    thread tB(runB, "\tB");
    
    tA.join();
    tB.join();
    
    std::cout << "\n";
}







//static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
//{
//    ((std::string*)userp)->append((char*)contents, size * nmemb);
//    return size * nmemb;
//}

//std::string fetchCurrentTime() {
//    CURL *curl;
//    CURLcode res;
//    std::string readBuffer;
//
//    curl = curl_easy_init();
//    if (curl) {
//        curl_easy_setopt(curl, CURLOPT_URL, "https://worldtimeapi.org/api/timezone/Japan");
//        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
//        res = curl_easy_perform(curl);
//        curl_easy_cleanup(curl);
//
//        // Parse the response to extract the time
//        try {
//            auto jsonResponse = nlohmann::json::parse(readBuffer);
//            return jsonResponse["datetime"];
//        } catch(const std::exception& e) {
//            std::cerr << "JSON parse error: " << e.what() << '\n';
//            return "";
//        }
//    }
//    return "";
//}

