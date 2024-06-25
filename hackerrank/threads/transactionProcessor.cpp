//
//  transactionProcessor.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 29.05.24.
//

#include "transactionProcessor.hpp"

#include <string>
#include <map>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

/*
 // You are tasked with implementing a transaction processor for tracking balances. The goal is to manage balances for various users and process transactions, including cash deposits and transfers. Each transaction may have a processing time, indicating when the amount becomes available to the receiver.
 // Usage Example
 final processor = TransactionProcessor();

 processor.deposit("Alice", 50);

 processor.transfer(from: "Alice", to: "Bob", amount: 20, processingTime: 1); // returns true
 processor.transfer(from: "Bob", to: "Carol", amount: 20, processingTime: 1); // returns false

 processor.incrementDay();
 processor.transfer(from: "Bob", to: "Carol", amount: 20, processingTime: 1); // returns true
 Tech "coding" video interview with Andrei Shemetau for Senior Flutter Developer
 */


using namespace std;


class BankAccount {
    mutex balance_mutex;
    
    int id;
    string name;
    int balance;
    
public:
    void deposit(int amount){
        unique_lock<mutex> lock(balance_mutex);
        balance += amount;
        this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << "deposit " << endl;
    }
    
    int getBalance() {
        unique_lock<mutex> lock(balance_mutex);
        this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << "balance " << endl;
        return balance;
    }
    
    bool withdraw(int amount) {
        unique_lock<mutex> lock(balance_mutex);
        if (balance < amount) return false;
        balance -= amount;
        this_thread::sleep_for(std::chrono::milliseconds(100));
        cout << "withdraw " << endl;
        return true;
    }
};


struct Transaction{
    string date;
    int fromAccountId;
    int toAccountId;
    int amount;
};


class TransactionProcessor {
    mutex resource_mutex;
    map<int, BankAccount> accounts;
    map<string,vector<Transaction>> transactions;
    chrono::system_clock::time_point currentDate = chrono::system_clock::now();
    
    string dateToString(chrono::system_clock::time_point date) {
        auto in_time_t = chrono::system_clock::to_time_t(date);
        stringstream ss;
        ss << put_time(localtime(&in_time_t), "%Y-%m-%d");
        return ss.str();
    }
    
public:
    
    void deposit(int accountId, int amount){
        accounts[accountId].deposit(amount);
    }
    
    bool transfer(int fromAccountId, int toAccountId, int amount, int processingDays){
        unique_lock<mutex> lock(resource_mutex);
        bool result = accounts[fromAccountId].withdraw(amount);
        if (!result) return result;
        if (processingDays > 0){
            auto trDate = currentDate + chrono::days(processingDays);
            string strTrDate = dateToString(trDate);
            Transaction tr = {strTrDate, fromAccountId, toAccountId, amount};
            transactions[strTrDate].push_back(tr);
        } else {
            accounts[toAccountId].deposit(amount);
        }
        return result;
        
    }
    
    void incrementDate(){
        unique_lock<mutex> lock(resource_mutex);
        currentDate = currentDate + chrono::days(1);
        string strCurrentDate = dateToString(currentDate);
        vector<Transaction> trs = transactions[strCurrentDate];
        for (int i=0; i<trs.size(); i++){
            Transaction tr = trs[i];
            accounts[tr.toAccountId].deposit(tr.amount);
        }
        transactions.erase(strCurrentDate);
    }
};

