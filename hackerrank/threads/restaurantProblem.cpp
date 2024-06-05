//
//  restaurantProblem.cpp
//  hackerrank
//
//  Created by Andrei Shemetau on 05/06/2024.
//

#include "restaurantProblem.hpp"
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>

/* https://medium.com/nuances-of-programming/c-%D1%87%D0%B0%D1%81%D1%82%D1%8C-3-%D1%81%D0%B8%D0%BD%D1%85%D1%80%D0%BE%D0%BD%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F-%D0%BF%D0%BE%D1%82%D0%BE%D0%BA%D0%BE%D0%B2-%D0%B2-%D1%80%D0%B5%D1%81%D1%82%D0%BE%D1%80%D0%B0%D0%BD%D0%B5-6136f46896ee
 */

class Restaurant {
    enum class Status { idle, newOrder, ready };
    Status orderStatus = Status::idle;
    std::mutex order;
    std::condition_variable orderBell;
    
public:

    void chef() {
        
        std::unique_lock<std::mutex> ul(order);
        orderBell.wait(ul, [=]() { return orderStatus == Status::newOrder; });
        //приготовление блюд из заказа
        printf("cooking\n");
        orderStatus = Status::ready;
        orderBell.notify_one();
      
    }

    void waiter() {
        {
            std::lock_guard<std::mutex> lg(order);
            orderStatus = Status::newOrder;
            orderBell.notify_one();
        } // lg вне области видимости = order.unlock()
        
        std::unique_lock<std::mutex> ul(order);
        orderBell.wait(ul, [=]() { return orderStatus == Status::ready; });
        orderStatus = Status::idle;
        ul.unlock();
        printf("delivering\n");
    }

};

void executeRestaurant_ex(){
    Restaurant restaurant;
       std::thread chef(&Restaurant::chef, std::ref(restaurant));
       std::thread waiter(&Restaurant::waiter, std::ref(restaurant));
       chef.join();
       waiter.join();
    return;
}
