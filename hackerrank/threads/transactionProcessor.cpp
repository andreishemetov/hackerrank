//
//  transactionProcessor.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 29.05.24.
//

#include "transactionProcessor.hpp"

#include <string>
#include <map>


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

/*

class Client {
    int id;
    string name;
    int amount;
    
public:
    void deposit(int sum){
        amount += sum;
    }
    
    int getAmount() {
        return amount;
    }
    
    void reduce(int sum) {
        amount -= sum;
    }
};

class Transaction {
    int date;
    int clientFromId;
    int clientToId;
    int amount;
};

class Processor {
    map<int, Client> clients;
    map<int,vector<Transaction>> transactions;
    int currentDate = 0;
    
    void deposit(int clientId, int amount){
        clients[clientId].deposit(amount);
    }
    
    bool transfer(int fromClientId, int toClientId, int amount, int time){
        int date = currentDate + time;
        bool res = clients[fromClientId].getAmount() >= amount;
        if (res) {
            Transaction tr = new Transaction(date, fromClientId, toClientId, amount);
            
            transactions[date].push_back(tr);
        }
        
        return res;
        
    }
    
    void incrementDate(){
        currentDate +=1;
        vector<Transaction> trs = transactions[currentDate];
        for (int i=0; i<trs.size(); i++){
            Transaction tr = trs[i];
            clients[tr.clientFromId].reduce(tr.amount);
            clients[tr.clientToId].deposit(tr.amount);
    }
        transactions.remove[currentDate];
    }
    
    
};

*/
